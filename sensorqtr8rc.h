#pragma once

#ifndef _sensorqtr8rc_h
#define _sensorqtr8rc_h

#include <Arduino.h>
#include <QTRSensors.h>

//numero maximo de sensores en qtr8-rc
#define MAX_SENSOR_COUNT 8

class SensorQtr8RC {
public:
  SensorQtr8RC();
  ~SensorQtr8RC();

  void configurarPines(const uint8_t* pins, uint8_t sensorCount);
  void calibrar();
  int obtenerPosicion();

  //funciones secundarias
  unsigned int at(uint8_t ithSensor);
  void probarSensores();

private:
  QTRSensors qtr;
  unsigned int sensado[MAX_SENSOR_COUNT];
};

#endif