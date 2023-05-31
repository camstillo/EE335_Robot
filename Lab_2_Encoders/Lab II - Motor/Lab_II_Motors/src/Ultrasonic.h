/*
In this header file, a set of commands for the ultrasonic sensor will be written to detect an incoming object in 
front of the robot. This will be implemented in the drivetrain class as the robot will automatically sense for an
object in front of it and stop if the distance is below some threshold. This means that we'll need a separate state
machine which will find the distance while taking as little processing power as possible since the motors will be 
running at the same time
*/
#include "StateMachine.h"

#define ECHO_PIN 8
#define TRIG_PIN 7

class Ultrasonic : public StateMachine {
public:
    //required public functions & variables
    void trigReq();
    uint16_t distance = 25;

    //class constructor
    Ultrasonic() : StateMachine(ST_MAX_STATES) {};

private:
    //private variables
    unsigned long startTime = 0;
    unsigned long pulseWidth = 0;

    //State Functions
    void ST_Idle();
    void ST_PulsePoll();
    void ST_EchoRec();

    //State table
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Ultrasonic::ST_Idle)
        STATE_MAP_ENTRY(&Ultrasonic::ST_PulsePoll)
        STATE_MAP_ENTRY(&Ultrasonic::ST_EchoRec)
    END_STATE_MAP

    //enumerate states
    enum {
        ST_IDLE,
        ST_PULSE_POLL,
        ST_ECHO_REC,
        ST_MAX_STATES
    };
};