#include "motores.h"

Motores::Motores() {
}

Motores::~Motores() {
}

void Motores::configurarPines(uint8_t izq1_pin, uint8_t izq2_pin, uint8_t pwm_izq_pin, uint8_t der1_pin, uint8_t der2_pin, uint8_t pwm_der_pin) {
  izq1 = izq1_pin, izq2 = izq2_pin, pwmi = pwm_izq_pin;
  der1 = der1_pin, der2 = der2_pin, pwmd = pwm_der_pin;
  pinMode(izq1, OUTPUT);
  pinMode(izq2, OUTPUT);
  pinMode(der1, OUTPUT);
  pinMode(der2, OUTPUT);
  velocidad(0, 0);

  //cambiando la frecuencia de pwm para timer 2(pines 3 y 11)

  //TCCR2B = TCCR2B & B11111000 | B00000001;
  //set timer 2 divisor to     1 for PWM frequency of 31372.55 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000010;
  //set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz

  TCCR2B = TCCR2B & B11111000 | B00000011;
  //set timer 2 divisor to    32 for PWM frequency of   980.39 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000100;
  //set timer 2 divisor to    64 for PWM frequency of   490.20 Hz (The DEFAULT)

  //TCCR2B = TCCR2B & B11111000 | B00000101;
  //set timer 2 divisor to   128 for PWM frequency of   245.10 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000110;
  //set timer 2 divisor to   256 for PWM frequency of   122.55 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000111;
  //set timer 2 divisor to  1024 for PWM frequency of    30.64 Hz
}

void Motores::velocidad(int velocidad_izq, int velocidad_der) {
  vel_izq = velocidad_izq;
  vel_der = velocidad_der;
}

void Motores::mover() {
  if (vel_izq >= 0) {
    digitalWrite(izq1, HIGH);
    digitalWrite(izq2, LOW);
  } else {
    digitalWrite(izq1, LOW);
    digitalWrite(izq2, HIGH);
    vel_izq *= -1;
  }

  if (vel_der >= 0) {
    digitalWrite(der1, HIGH);
    digitalWrite(der2, LOW);
  } else {
    digitalWrite(der1, LOW);
    digitalWrite(der2, HIGH);
    vel_der *= -1;
  }

  analogWrite(pwmi, vel_izq);
  analogWrite(pwmd, vel_der);
}

void Motores::freno() {
  velocidad(0, 0);
  digitalWrite(izq1, LOW);
  digitalWrite(izq2, LOW);
  digitalWrite(der1, LOW);
  digitalWrite(der2, LOW);
  analogWrite(pwmi, 0);
  analogWrite(pwmd, 0);
}

/* Por falta de encoders aproximamos un giro de
     90 grados */
void Motores::rotar90() {
  freno();
  velocidad(130, -73);  //~8.33 voltios, bateria litio 2 celdas
  mover();
  delay(1000);
  freno();
}

void Motores::probarMotores() {
  velocidad(80, 80);
  mover();
  delay(500);
  velocidad(-80, -80);
  mover();
  delay(500);
  freno();
}