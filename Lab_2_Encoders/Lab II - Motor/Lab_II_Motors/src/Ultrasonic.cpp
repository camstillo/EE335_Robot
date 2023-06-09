/*
Defines functions from ultrasonic header file
*/
#include "Ultrasonic.h"

void Ultrasonic::begin(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void Ultrasonic::sendPulse(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

float Ultrasonic::distCalc(unsigned long pulse){
  //340 m/s * 1/10^6 s/us * 100 cm/m /2 = 0.017 
  //cast to int since the sensor isn't that accurate anyways
  return float(pulse)*0.017;
}

bool Ultrasonic::getDistance(){
  Ultrasonic::sendPulse();
  unsigned long pulseWidth = pulseIn(ECHO_PIN, HIGH, 600);
  if(pulseWidth == 0) pulseWidth = 1000;
  if(uint16_t(Ultrasonic::distCalc(pulseWidth)) < 5) return true;
  return false;
}

