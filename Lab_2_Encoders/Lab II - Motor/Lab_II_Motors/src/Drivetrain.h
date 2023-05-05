/*
In this file, all the motors are instantiated and combined into a single object to be driven either right,
left, forward, backwards, or idle. This is meant to be passed control data through another class, controlData, such that 
when either the bluetooth or line following modes take control, all four motors can be driven very easily with a single
command. The motor objects will be instantiated in this header file and the begin statement done in the next. 
*/

#ifndef _DRIVETRAIN_H
#define _DRIVETRAIN_H
#include "StateMachine.h"
#include "Motor.h"

class ControlData : public EventData {
    public:
    char direction;
    int speed;
};

class Drivetrain : public StateMachine {
    public:
    //declare contstructor 
    Drivetrain() : StateMachine(ST_MAX_STATES) {};

    //declare transition functions
    void moveFunction(ControlData*);
    void begin();

    //define all the directions which ControlData can take
    enum {
        STOP,
        FWD,
        RIGHT,
        LEFT,
        BACK
    };

    private:
    //instantiate motor objects for each wheel
    Motor FrontRight;
    Motor FrontLeft;
    Motor BackRight;
    Motor BackLeft;

    //declare state functions
    void ST_Idle                    ();
    void ST_Forward     (ControlData*);
    void ST_Backward    (ControlData*);
    void ST_Left        (ControlData*);
    void ST_Right       (ControlData*);

    //define state map for transitions
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Drivetrain::ST_Idle)
        STATE_MAP_ENTRY(&Drivetrain::ST_Forward)
        STATE_MAP_ENTRY(&Drivetrain::ST_Right)
        STATE_MAP_ENTRY(&Drivetrain::ST_Left)
        STATE_MAP_ENTRY(&Drivetrain::ST_Backward)
    END_STATE_MAP;

    //enumerate different states 
    enum {
        ST_IDLE,
        ST_FORWARD,
        ST_RIGHT,
        ST_LEFT,
        ST_BACKWARD,
        ST_MAX_STATES
    };

    //define the motor numbers for each motor.
    #define FRONT_RIGHT 4
    #define FRONT_LEFT 2
    #define BACK_LEFT 1
    #define BACK_RIGHT 3

};


#endif