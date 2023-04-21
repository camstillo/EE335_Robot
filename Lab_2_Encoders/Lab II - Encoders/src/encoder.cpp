#include "encoder.h"
#include <Arduino.h>

//encoder variables
const uint8_t encoder::PIN = 2;
volatile int encoder::count = 0;
unsigned long encoder::startTime = 0;
unsigned long encoder::pulseWidth = 0;
bool encoder::intFlag = LOW;


//encoder function
void encoder::begin(uint8_t pinNumber){
    attachInterrupt(digitalPinToInterrupt(pinNumber),interruptFlag, CHANGE);
}

void encoder::interruptFlag(){
    
}

//Low state operations
void low::enter(){}
state* low::run(){
    digitalWrite(encoder::PIN, LOW);
    if(encoder::intFlag){
        return &Rise;
    } else {
        return this;
    }
}

//rising state operation
void rising::enter(){
    encoder::count++;
    encoder::startTime = millis();
}
state* rising::run(){
    return &High;
}

//high state operation
void high::enter(){}
state* high::run(){
    digitalWrite(encoder::PIN, HIGH);
    if(encoder::intFlag){
        return &Fall;
    } else {
        return this;
    }
}

//falling state operation
void falling::enter(){
    encoder::pulseWidth = millis() - encoder::startTime;
}
state* falling::run(){
    return &Low;
}

