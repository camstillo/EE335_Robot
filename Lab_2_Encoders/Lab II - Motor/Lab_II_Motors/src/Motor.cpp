/*
Defines functions in Motor.h
*/
#include "Motor.h"

//declare begin function
void Motor::begin(uint8_t motorNumber) {
    Motor::Motor_Number = motorNumber;
    MotorShield.begin();
}

void Motor::setSpeed(MotorData * pData){
    BEGIN_TRANSITION_MAP
        TRANSITION_MAP_ENTRY (ST_RUN)        //IDLE
        TRANSITION_MAP_ENTRY (ST_RUN)        //RUN
        TRANSITION_MAP_ENTRY (EVENT_IGNORED) //STOP
    END_TRANSITION_MAP(pData)
}

void Motor::halt(){
    BEGIN_TRANSITION_MAP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED) //IDLE
        TRANSITION_MAP_ENTRY (ST_STOP)       //RUN
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN) //STOP
    END_TRANSITION_MAP(NULL)
}

void Motor::ST_Idle(){
    //do nothing
}

void Motor::ST_Run(MotorData * speed){
    //temporary variable to cast speed to uint16_t
    //consider making a function which takes a float
    //and returns a value between -255 and 255
    uint16_t _speed = (uint16_t)speed;

    //How to drive the motor in the run state
    if(_speed == 0){
        this->halt();
    }else if(_speed < 0 && _speed >= -255){
        DC_Motor->setSpeed(_speed);
        DC_Motor->run(BACKWARD);
    } else if(_speed > 0 && _speed <= 255) {
        DC_Motor->setSpeed(_speed);
        DC_Motor->run(FORWARD); 
    } else if (_speed > 255){
        DC_Motor->setSpeed(255);
        DC_Motor->run(FORWARD); 
    } else {
        DC_Motor->setSpeed(255);
        DC_Motor->run(BACKWARD); 
    }
}

void Motor::ST_Stop(){
    //completely stop the motor
    DC_Motor->fullOff();

    //Automatically transition to IDLE state
    InternalEvent(ST_IDLE);
}