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
#include "Encoder.h"
#include "Ultrasonic.h"

//pins for encoders
#define IN_1 2
#define IN_2 3

//PID variables
#define K_P 1
#define K_I 1
#define K_D 0.01

class ControlData : public EventData {
    public:
    char direction;
    float speed;
};

class Drivetrain : public StateMachine {
    public:
    //declare contstructor 
    Drivetrain() : StateMachine(ST_MAX_STATES) {};

    //declare transition functions
    void moveFunction(ControlData*);
    void begin();

    //Encoder Interrupt functions
    void leftInterruptFunc();
    void rightInterruptFunc();

    //Instantiate encoder objects
    Encoder leftEncoder;
    Encoder rightEncoder;

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

    //instantiate ultrasonic object
    Ultrasonic frontSensor;

    //PID Functions
    int8_t calcInputPID(float, uint32_t);

    //PID Variables
    uint8_t error;
    uint8_t lastError;
    const float f_timeInterval = 0.2;
    const float f_pulsePerSecPerBit = 0.764;
    uint8_t lastPIDVal = 0;
    unsigned long lastTime = 0;
    uint8_t intSum = 0;
    uint16_t intWindupCount = 0;
    

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