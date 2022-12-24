#pragma once

#ifndef _motores_h
#define _motores_h

#define VELOCIDAD_DEFAULT 100

#include <Arduino.h>

class Motores {
public:
  Motores();
  ~Motores();

  void configurarPines(uint8_t izq1_pin, uint8_t izq2_pin, uint8_t pwm_izq_pin, uint8_t der1_pin, uint8_t der2_pin, uint8_t pwm_der_pin);
  void velocidad(int velocidad_izq, int velocidad_der);
  void mover();

  //funciones secundarias
  void freno();
  void rotar90();
  void probarMotores();

private:
  uint8_t izq1;  // pin
  uint8_t izq2;  // pin
  uint8_t pwmi;  // pin
  uint8_t der1;  // pin
  uint8_t der2;  // pin
  uint8_t pwmd;  // pin

  int vel_izq = VELOCIDAD_DEFAULT;
  int vel_der = VELOCIDAD_DEFAULT;
};

#endif