#include "pid.h"

PID::PID() {
}
PID::~PID() {
}

void PID::configurarConstantes(float Kp, float Ki, float Kd) {
  KP = Kp, KI = Ki, KD = Kd;
  setpoint = proporcional = integral = derivativo = 0;
  anteriorProp = 0;
}
void PID::afinarConstantes(float Kp, float Ki, float Kd){
  KP = Kp, KI = Ki, KD = Kd;
}
void PID::configurarSetPoint(int setPoint) {
  setpoint = setPoint;
}
int PID::calcular(int posicion) {
  proporcional = setpoint - posicion;
  derivativo = proporcional - anteriorProp;
  integral += proporcional;
  anteriorProp = proporcional;

  return proporcional*KP + integral*KI + derivativo*KD;
}