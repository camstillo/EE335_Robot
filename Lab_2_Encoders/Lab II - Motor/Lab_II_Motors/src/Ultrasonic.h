/*
In this header file, a set of commands for the ultrasonic sensor will be written to detect an incoming object in 
front of the robot. This will be implemented in the drivetrain class as the robot will automatically sense for an
object in front of it and stop if the distance is below some threshold. This means that we'll need a separate state
machine which will find the distance while taking as little processing power as possible since the motors will be 
running at the same time
*/
#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"
#define ECHO_PIN 6
#define TRIG_PIN 7

class Ultrasonic {
public:
    //public functions
    bool getDistance();
    void begin();

private:
    //private functions
    void sendPulse();
    float distCalc(unsigned long);
};

#endif