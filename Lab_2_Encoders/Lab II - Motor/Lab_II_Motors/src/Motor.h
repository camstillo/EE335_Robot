/*
This header file defines the state machine for a motor. It has 4 states: halt, start, run, & stop.
This allows the motor to take in commands a lot easier than otherwise. The adafruit motor library can be 
used to write the functions which change speed, but the states will be controlled by the same state machine 
class that was used for the encoders. Unlike the encoders, the motor will actually have some event data called
speed, which will determine how fast the motor is set to. This class does not include the servo motor.
*/
#ifndef _MOTOR_H
#define _MOTOR_H

#include "StateMachine.h"
#include "Wire.h"
#include "Adafruit_MotorShield.h"
#include "Adafruit_MS_PWMServoDriver.h"

class MotorData : public EventData {
    uint16_t speed;
};

class Motor : public StateMachine{
    public:
    //Motor constructor
    Motor() : StateMachine(ST_MAX_STATES) {};

    //declare motor shield objects
    Adafruit_MotorShield MotorShield = Adafruit_MotorShield();
    Adafruit_DCMotor *DC_Motor = MotorShield.getMotor(Motor::Motor_Number);

    //transition table functions
    void setSpeed(MotorData*);
    void halt();
    void begin(uint8_t);

    private:
    //declare state functions
    void ST_Idle();
    void ST_Run(MotorData*);
    void ST_Stop();

    //define state map
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Motor::ST_Idle)
		STATE_MAP_ENTRY(&Motor::ST_Run)
        STATE_MAP_ENTRY(&Motor::ST_Stop)
    END_STATE_MAP

    //declare states and associated numbers for StateMachine class to function
    enum MOTOR_STATES {
        ST_IDLE,
        ST_RUN,
        ST_STOP,
        ST_MAX_STATES
    };

    //define which motor is used
    uint8_t Motor_Number;
};

#endif