#pragma once

#ifndef _ircontrol_h
#define _ircontrol_h

#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 2
#define TONE_PIN 12

// importante cambiar el timer a "1"(IrRemote usa por default el timer "2",
// CONFLICTOS:  1) los motores usan el timer 2( ya que uso pines 3 y 11)
//              2) el buzzer usa el timer 2 por default
// OJO: Si no funciona modificar la libreria directamente
//   |---> ../libraries/IRremote/src/private/IRTimer.hpp
#define IR_USE_AVR_TIMER1 //se cambia a timer 1

//OJO: si se agregan mas comandos, modificar IRcontrol::capturar() tambien
enum Comando {  //para control remoto samsumg
  VACIO = 255,
  BOTON_USB = 77,
  BOTON_OK = 70,
  BOTON_MENU = 17,
  BOTON_1 = 1,
  BOTON_2 = 2,
  BOTON_3 = 3,
  BOTON_4 = 4,
  BOTON_5 = 5,

};

class IRControl {
public:

  IRControl();
  ~IRControl();

  void iniciar();
  bool capturar();
  Comando comandoActual();
  void escanearComandos();

private:
  Comando cmd;
  int tiempo;
};

//implementacion de funciones
IRControl::IRControl() {
}

IRControl::~IRControl() {
}

void IRControl::iniciar() {
  pinMode(LED_BUILTIN, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  cmd = Comando::VACIO;
  tiempo = millis();
}

Comando IRControl::comandoActual() {
  return cmd;
}

bool IRControl::capturar() {

  if (!IrReceiver.decode()) return false;
  if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW) {
    cmd = Comando::VACIO;
  } else if (IrReceiver.decodedIRData.protocol == 16) {  // || IrReceiver.decodedIRData.protocol == 17) {  // boton: se presiona una vez->samsung(16) y se mantiene presionado samsung-lg(17)
    Serial.println("Capturo comando ojo!");
    switch (IrReceiver.decodedIRData.command) {
      case Comando::BOTON_OK:
        cmd = Comando::BOTON_OK;
        break;
      case Comando::BOTON_USB:
        cmd = Comando::BOTON_USB;
        break;
      case Comando::BOTON_MENU:
        cmd = Comando::BOTON_MENU;
        break;
      case Comando::BOTON_1:
        cmd = Comando::BOTON_1;
        break;
      case Comando::BOTON_2:
        cmd = Comando::BOTON_2;
        break;
      case Comando::BOTON_3:
        cmd = Comando::BOTON_3;
        break;
      case Comando::BOTON_4:
        cmd = Comando::BOTON_4;
        break;
      case Comando::BOTON_5:
        cmd = Comando::BOTON_5;
        break;
      default:
        cmd = Comando::VACIO;
    }
  }
  IrReceiver.decodedIRData.protocol = 0;
  IrReceiver.decodedIRData.command = 0;
  IrReceiver.resume();  // se prepara para el siguiente valor
  return cmd == Comando::VACIO ? false : true;
}


//poner en "void loop()" para escanear comandos del control remoto
void IRControl::escanearComandos() {
  if (IrReceiver.decode()) {  // captura un codigo IR
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW) {
      //Serial.println(F("Buffer overflow detected"));
    } else {
      Serial.println();
      Serial.print("Protocolo: ");
      Serial.print(IrReceiver.decodedIRData.protocol);
      Serial.println(", [16:samsung y 17:samsung-lg segun <IRProtocol.h>]");
      Serial.print("Comando: ");
      Serial.println(IrReceiver.decodedIRData.command);
    }
    IrReceiver.resume();  // se prepara para el siguiente valor
  }
}

#endif