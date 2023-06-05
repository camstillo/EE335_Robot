/*
In this header file, a set of functions to allow the robot to follow a line will be created. The robot will 
have 4 states: on line, right of line, left of line, and idle. The robot will start in the on line state, which means 
that it should drive forward until some change is detected. When one of the sensors is triggered, the robot will turn 
the opposite direction as the sensor until the sensor is untriggered. It will then revert back to the drive state,
where it will continue to go forward. If the robot turns a certain amount and doesn't have either sensor trigger,
the robot will go into an idle state. If both sensors are triggered at the same time, then the robot will also go 
into an idle state. This class is meant to be constructed, then destructed, so make sure after the object has reached
the end of the line, the entire object is destroyed. 
*/
#ifndef LINE_FOLLOW_H
#define LINE_FOLLOW_H
#include "StateMachine.h"
#include "Drivetrain.h"

#define L_LF 19
#define R_LF 18

//create state machine class for PID follower
class LineFollow {
    public:
    //pass constructor drivetrain object so that the drivetrain object in main
    //doesn't have to be deconstructed for this to work
    LineFollow(Drivetrain *);

    //public "run" function as well as "done" flag
    void follow();
    bool endOfLine = 0;

    private:
    //drivetrain pointer object
    Drivetrain * p_dTrain;

    //run functions
    void run();
    void leftInterrupt();
    void rightInterrupt();
    void stop();
};
#endif

/*
To instantiate module:
// while(n < 1){
  //   LineFollow LF_base = LineFollow(&base);
  //   LF_base.follow();
  //   delete &LF_base;
  //   n++;
  // }
*/