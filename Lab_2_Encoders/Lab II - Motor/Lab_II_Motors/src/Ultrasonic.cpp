/*
Defines functions from ultrasonic header file
*/
#include "Ultrasonic.h"
#include "Arduino.h"

void Ultrasonic::trigReq() {
    //send the ultrasonic pulse and transition to 
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    InternalEvent(ST_PULSE_POLL);
}

void Ultrasonic::ST_Idle() {}

void Ultrasonic::ST_PulsePoll() {
    if((micros() - this->startTime) >= 23000) InternalEvent(ST_IDLE);
    if(digitalRead(TRIG_PIN)){
        this->startTime = micros();
        InternalEvent(ST_ECHO_REC);
    }
}

void Ultrasonic::ST_EchoRec() {
    if((micros() - this->startTime) >= 23000) {
        this->distance = 25;
        this->startTime = 0;
        InternalEvent(ST_IDLE);
    } else if(!digitalRead(TRIG_PIN)){
        this->pulseWidth = micros() - this->startTime;
        //340 m/s * 1/10^6 s/us * 100 cm/m /2 = 0.017 
        //cast to int since the sensor isn't that accurate anyways
        this->distance = uint16_t(this->pulseWidth*0.017); 
        this->startTime = 0;
        InternalEvent(ST_IDLE);
    }
}