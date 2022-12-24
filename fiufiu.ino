#include "ircontrol.hpp"
#include "pines.h"
#include "motores.h"
#include "sensorqtr8rc.h"
#include "altavoz.h"
#include "pid.h"

//motores
Motores motores;
int crucero = 100;  //velocidad constante
int vel = crucero;  //velocidad variable

//regla de sensor qtr8-rc
SensorQtr8RC qtr;
const uint8_t sensorCount = 8;

//altavoz buzzer
Altavoz tonos;

//control remoto IR(infrarrojo)
IRControl controlRemoto;
Comando comando;

//pid control
PID pid;
float kp, ki, kd;

//maquina de estados
bool estadoSeguidor = false;
bool estadoReposo = true;
void EjecutarComando();
void Seguidor();
void Reposo();
void Calibracion();

void setup() {
  //iniciando serial
  Serial.begin(115200);

  //configurando el altavoz buzzer
  tonos.configuraPin(BUZZER);

  //configurando boton(pull down) de calibracion
  pinMode(BTN1, INPUT);

  // configurando los sensores qtr8-rc
  qtr.configurarPines((const uint8_t[]){ S1, S2, S3, S4, S5, S6, S7, S8 }, sensorCount);

  //configurando los motores
  motores.configurarPines(IZQ1, IZQ2, PWMI, DER1, DER2, PWMD);
  motores.velocidad(vel, vel);

  //configurando el control remoto IR, internamente puesto a pin D2
  controlRemoto.iniciar();

  //configurando el pid control
  pid.configurarConstantes(kp = 0.05, ki = 0.00018, kd = 0.15);
  pid.configurarSetPoint(3500);

  //finalmente inicia robot seguidor de linea
  tonos.beep();

  //iniciar proceso de calibracion(al pulsar boton)
  //Calibracion();
}

void loop() {
  //controlRemoto.escanearComandos();

  if (controlRemoto.capturar()) {
    comando = controlRemoto.comandoActual();
    EjecutarComando();
  }

  else if (estadoReposo)
    Reposo();

  else if (estadoSeguidor)
    Seguidor();
}

void EjecutarComando() {
  Serial.print("Comando: ");
  Serial.println(comando);
  IrReceiver.stop();
  motores.freno();
  switch (comando) {
    case Comando::BOTON_MENU: //reposo
      estadoSeguidor = false;
      estadoReposo = true;
      tonos.beep();
      break;
    case Comando::BOTON_OK: //seguidor de linea
      estadoReposo = false;
      estadoSeguidor = true;
      tonos.turbo();
      break;
    case Comando::BOTON_1: //modo 1
      estadoReposo = true;
      estadoSeguidor = false;
      modo1();
      tonos.mejora();
      break;
    case Comando::BOTON_2: //modo 2
      estadoReposo = true;
      estadoSeguidor = false;
      modo2();
      tonos.mejora();
      break;
    case Comando::BOTON_3: //modo 3
      estadoReposo = true;
      estadoSeguidor = false;
      modo3();
      tonos.mejora();
      break;
  }
  IrReceiver.start();
  IrReceiver.resume();
}

void Reposo() {
  motores.freno();
}

void Calibracion() {

  while(digitalRead(BTN1) == LOW);
  tonos.calibra();
  Serial.print("inicia");
  qtr.calibrar();
  Serial.print("final");
  tonos.finDeTono();
  while(digitalRead(BTN1) == LOW);
  tonos.beep();
}

void Seguidor() {
  vel = pid.calcular(qtr.obtenerPosicion());
  motores.velocidad(crucero + vel, crucero - vel);
  motores.mover();
}

void modo1(){
  crucero = 120;
  pid.afinarConstantes(kp = 0.05, ki = 0.00018, kd = 0.15);
}

void modo2(){
  crucero = 130;
}

void modo3(){
  crucero = 140;
  pid.afinarConstantes(kp = 0.1, ki = 0.00018, kd = 0.15);
}