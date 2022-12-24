#pragma once

#ifndef _pid_h
#define _pid_h

#define DEFAULT_PID_VALUES 0

class PID {
public:
  PID();
  ~PID();

  void configurarConstantes(float Kp, float Ki, float Kd);
  void afinarConstantes(float Kp, float Ki, float Kd);
  void configurarSetPoint(int setpoint);
  int calcular(int posicion);

private:

  float KP; //9;      //0.18;   // constante proporcional
  float KI; //0.002;  // constante integral
  float KD; //4;      // constante derivativa

  int setpoint;// = 20;  //15 cm del obstaculo
  int proporcional; //0;       // proporcional
  int integral; //0;       // integral
  int derivativo; //0;      // derivativa
  int anteriorProp;//;  // proporcional anterior
};

#endif