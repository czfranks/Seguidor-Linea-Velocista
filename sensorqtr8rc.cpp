#include "sensorqtr8rc.h"

SensorQtr8RC::SensorQtr8RC() {
}

SensorQtr8RC::~SensorQtr8RC() {
}

void SensorQtr8RC::configurarPines(const uint8_t* pins, uint8_t sensorCount) {
  qtr.setTypeRC();
  qtr.setSensorPins(pins, sensorCount);
}

void SensorQtr8RC::calibrar() {
  delay(1000);
}

int SensorQtr8RC::obtenerPosicion() {
  qtr.read(sensado);
  return qtr.readLineBlack(sensado);
}

unsigned int SensorQtr8RC::at(uint8_t ithSensor) {
  if (ithSensor >= MAX_SENSOR_COUNT) return 0;
  return sensado[ithSensor];
}

void SensorQtr8RC::probarSensores() {
  obtenerPosicion();
  for (uint8_t i = 0; i < MAX_SENSOR_COUNT; i++) {
    Serial.print(at(i));
    Serial.print(' ');
  }
  Serial.println();

  delay(250);
}