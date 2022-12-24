#pragma once

#ifndef _altavoz_h
#define _altavoz_h

#include <Arduino.h>
#include "pitches.h"

#define DEFAULT_ALTAVOZ_PIN 2

class Altavoz {
public:
  Altavoz();

  ~Altavoz();

  void beep();
  void mejora();
  void calibra();
  void gameover();
  void finDeTono();
  void silencio();
  void turbo();
  void sad();
  void configuraPin(uint8_t pin);

private:
  uint8_t mPin = DEFAULT_ALTAVOZ_PIN;
};

#endif