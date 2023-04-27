#include "encoder.h"
#include <Arduino.h>

//encoder variables
// uint8_t encoder::PIN = 5;
// volatile int encoder::count = 0;
// unsigned long encoder::startTime = 0;
// unsigned long encoder::pulseWidth = 0;
// volatile bool encoder::intFlag = LOW;
encoder * encoder::instances [2] = { NULL, NULL };


//encoder function
void encoder::begin(uint8_t intPin, uint8_t ledPin){
    encoder::PIN = ledPin;
    pinMode (intPin, INPUT);
    pinMode (ledPin, OUTPUT);
    switch (intPin)
      {
      case 2: 
        attachInterrupt (digitalPinToInterrupt(intPin), switchPressedExt0, CHANGE);
        instances [0] = this;
      break;
        
      case 3: 
        attachInterrupt (digitalPinToInterrupt(intPin), switchPressedExt1, CHANGE);
        instances [1] = this;
      break;
      }
}

void encoder::switchPressedExt0(){
    if (encoder::instances [0] != NULL) 
      encoder::instances [0]->interruptFlag();
} 

void encoder::switchPressedExt1(){
    if (encoder::instances [1] != NULL) 
      encoder::instances [2]->interruptFlag();
} 

void encoder::interruptFlag(){
    encoder::intFlag = HIGH;
    digitalWrite(encoder::PIN,HIGH);
    //Serial.println("i");
}

//Low state operations
void low::enter(){}
state* low::run(){
    uint8_t encoder::*LEDPIN = &encoder::PIN;
    digitalWrite(encoder::*LEDPIN, LOW);
    if(encoder::intFlag){
        encoder::intFlag = LOW;
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
        encoder::intFlag = LOW;
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

