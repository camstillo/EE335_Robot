/*
*/
#ifndef Gripper_h
#define Gripper_h

#include <Servo.h>
#include "StateMachine.h"

//Define Servo Pin
#define SERVO_PIN 9

class Gripper : public StateMachine {
private:
  
  Servo *m_gripper;
  
  //define state functions
  void ST_Closed();
  void ST_Open();

  //define states
  BEGIN_STATE_MAP
    STATE_MAP_ENTRY(&Gripper::ST_Open)
    STATE_MAP_ENTRY(&Gripper::ST_Closed)
  END_STATE_MAP

  //enumerate states
  enum {
    ST_OPEN,
    ST_CLOSED,
    ST_MAX_STATES
  };

public:
  //Public functions
  void begin(uint8_t);
  void changeState();
  uint16_t m_angle;

  //constructor
  Gripper() : StateMachine(ST_MAX_STATES) {};
};

#endif