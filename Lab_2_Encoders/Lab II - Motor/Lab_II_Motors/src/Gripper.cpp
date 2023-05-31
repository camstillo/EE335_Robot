#include "Gripper.h"

void Gripper::begin(uint8_t PIN) {
    m_gripper = new Servo();
    // m_gripper->begin();
    // m_gripper->setPWMFreq(27000000);
    m_gripper->attach(PIN,800,2200);
    //this->m_angle = m_gripper->read();
    //if(this->m_angle > 0){
      m_gripper->write(0);
    //}
}

void Gripper::changeState(){
  BEGIN_TRANSITION_MAP
    TRANSITION_MAP_ENTRY(ST_CLOSED)   //ST_CLOSED
    TRANSITION_MAP_ENTRY(ST_OPEN) //ST_OPEN
  END_TRANSITION_MAP(NULL)
}

void Gripper::ST_Open() {
  this->m_angle = m_gripper->read();
  if(this->m_angle < 170){
    m_gripper->write(170); //closed angle
  }
}

void Gripper::ST_Closed() {
  this->m_angle = m_gripper->read();
  if(this->m_angle > 0){
    m_gripper->write(0); //closed angle
  }
}