/*
Defines functions in Motor.h
*/
#include "Motor.h"


//declare begin function
void Motor::begin(uint8_t motorNumber) {
    MotorShield = Adafruit_MotorShield();
    Motor::Motor_Number = motorNumber;
    DC_Motor = MotorShield.getMotor(Motor::Motor_Number);
    MotorShield.begin();
}

void Motor::speedSet(MotorData * pData){
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

void Motor::ST_Run(MotorData * pData){
    //temporary variable to cast speed to uint16_t
    //consider making a function which takes a float
    //and returns a value between -255 and 255
    int _speed = pData->speed;

    //How to drive the motor in the run state
    if(_speed == 0){
        this->halt();
    }else if(_speed < 0 && _speed >= -255){
        DC_Motor->setSpeed(-1*_speed);
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