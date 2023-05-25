/*
In this header file, a set of functions to allow the robot to follow a line will be created. The robot will 
have 4 states: on line, right of line, left of line, and idle. The robot will start in the on line state, which means 
that it should drive forward until some change is detected. When one of the sensors is triggered, the robot will turn 
the opposite direction as the sensor until the sensor is untriggered. It will then revert back to the drive state,
where it will continue to go forward. If the robot turns a certain amount and doesn't have either sensor trigger,
the robot will go into an idle state. If both sensors are triggered at the same time, then the robot will also go 
into an idle state.
*/
#include "StateMachine.h"
#include "Drivetrain.h"

#define L_LF 18
#define R_LF 19

//create data class for PID follower
class FollowData : public EventData {

}; 

//create state machine class for PID follower
class LineFollow : public StateMachine {
    public:
    //declare constructor
    LineFollow() : StateMachine(ST_MAX_STATES) {};

    //interrupt Functions for the arduino
    void leftTrig();
    void rightTrig();

    //setup function
    void begin();

    //instantiate drivetrain base
    Drivetrain LF_Base;

    private:

    //State functions
    void ST_Run();
    void ST_L_Trig();
    void ST_R_Trig();
    void ST_Idle();

    //State map entries
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&LineFollow::ST_Run)
        STATE_MAP_ENTRY(&LineFollow::ST_L_Trig)
        STATE_MAP_ENTRY(&LineFollow::ST_R_Trig)
        STATE_MAP_ENTRY(&LineFollow::ST_Idle)
    END_STATE_MAP;

    //enumerate states
    enum {
        ST_RUN,
        ST_L_TRIG,
        ST_R_TRIG,
        ST_IDLE,
        ST_MAX_STATES
    };
};