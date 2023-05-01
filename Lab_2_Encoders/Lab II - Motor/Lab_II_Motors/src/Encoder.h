/*
This library includes a state machine which runs an encoder. Essentially, the state machine framework declared in 
the header files in this folder will be used to make an encoder state machine. This differs from the previous state
machine design because it uses an overall class with functions that include lookup tables. This will make it easier 
for group collaboration since each person can determine the functions necessary for a given action.
*/
#ifndef _ENCODER_H
#define _ENCODER_H
#include "StateMachine.h"
#include "Arduino.h"

class Encoder : public StateMachine {
    public:

    //constructor: make a state machine with ST_MAX_STATES on instantiation
    Encoder() : StateMachine(ST_MAX_STATES){};

    //intialize encoder object
    void begin(double);

    //declare encoder public variables
    uint8_t INT_PIN;
    double RADIUS;
    unsigned char bufCurrentState;
    double speed; 

    //external event functions
    void rise();
    void fall();

    private:
    //declare encoder private variables
    unsigned long startTime;
    unsigned long pulseWidth;
    uint16_t count;

    //determine encoder speed
    double getSpeed();

    //functions which declare what each state does while running
    void ST_Low(EventData*);
    void ST_High(EventData*);

    // state map to define state function order
    BEGIN_STATE_MAP
		STATE_MAP_ENTRY(&Encoder::ST_Low)
        STATE_MAP_ENTRY(&Encoder::ST_High)
    END_STATE_MAP

    enum E_States {
        ST_LOW = 0,
        ST_HIGH,
        ST_MAX_STATES
    };

};

#endif