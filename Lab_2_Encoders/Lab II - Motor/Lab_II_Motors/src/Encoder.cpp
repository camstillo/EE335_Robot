/*
Declare all the necessary functions for state machine operations
*/
#include "Encoder.h"

//initialize encoder
void Encoder::begin(){
    pinMode(Encoder::INT_PIN, INPUT);
    if(digitalRead(Encoder::INT_PIN)) Encoder::currentState = ST_HIGH;
    else Encoder::currentState = ST_LOW;
}

// double Encoder::getSpeed(){
//     double speed = 157.180*(Encoder::RADIUS/(Encoder::pulseWidth));
//     if(speed != INFINITY && speed <= 10)
//         return speed;
//     return NULL;
// }

//Rising edge event
void Encoder::rise(){
    //increment counter and start the pulse width timer
    Encoder::count++;
    // Encoder::startTime = millis();

    //decide which transition to occur between the 
    BEGIN_TRANSITION_MAP
        TRANSITION_MAP_ENTRY (ST_HIGH)    //ST_LOW
        TRANSITION_MAP_ENTRY (ST_HIGH)    //ST_HIGH
    END_TRANSITION_MAP(NULL)
    Encoder::bufCurrentState = currentState;
}

void Encoder::fall(){
    //find puslse width
    // Encoder::pulseWidth = millis() - startTime;

    //decide which transition to occur as falling happens
    BEGIN_TRANSITION_MAP
        TRANSITION_MAP_ENTRY (ST_LOW)    //ST_LOW
        TRANSITION_MAP_ENTRY (ST_LOW)           //ST_HIGH
    END_TRANSITION_MAP(NULL)
    Encoder::bufCurrentState = currentState;
}

void Encoder::ST_Low(EventData* pData){
    //Turn off LED
    // Encoder::speed = this->getSpeed();
    //wait for rise event
}

void Encoder::ST_High(EventData* pData){
    //light LED
    //wait for falling event
}