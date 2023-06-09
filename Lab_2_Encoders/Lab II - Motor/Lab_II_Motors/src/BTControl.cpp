/*
Define a set of functions from the BT control header
*/
#include "BTControl.h"

Bluetooth::Bluetooth(Drivetrain * _pDTrain, Gripper * _pGripper){
    //initialize serial
    pinMode(BT_RX, INPUT);
    pinMode(BT_TX, OUTPUT);
    Serial3.begin(9600);

    //Set object pointers
    p_Drivetrain = _pDTrain;
    p_Gripper = _pGripper;
}

void Bluetooth::BTCommand(uint8_t vector){
  for(uint8_t i = 0; i < 100; i++){
        ControlData * pData = new ControlData;
        pData->speed = 100;
        pData->direction = vector;
        p_Drivetrain->moveFunction(pData);
      }
      ControlData * pData = new ControlData;
      pData->direction = p_Drivetrain->STOP;
      p_Drivetrain->moveFunction(pData);
}

void Bluetooth::BT_Poll() {
    if(Serial3.available()){
    char controlChar = char(Serial3.read());
    switch(controlChar){
      case 'w':
       {
          for(uint8_t i = 0; i < 100; i++){
            ControlData * pData = new ControlData;
            pData->speed = 100;
            pData->direction = p_Drivetrain->FWD;
            p_Drivetrain->moveFunction(pData);
            }
            ControlData * pData = new ControlData;
            pData->direction = p_Drivetrain->STOP;
            p_Drivetrain->moveFunction(pData);
       }
      break;
      case 'a':
        {
          this->BTCommand(p_Drivetrain->LEFT);
        }
      break;
      case 's':
        {
          this->BTCommand(p_Drivetrain->BACK);
        }
      break;
      case 'd':
        {
          this->BTCommand(p_Drivetrain->RIGHT);
        }
      break;
      case 't':
        {
         p_Gripper->changeState();
        }
      break;
      case 'f':
        {
          LineFollow LF_Base = LineFollow(p_Drivetrain);
          LF_Base.follow();
        }
      break;
      default:
        {
          ControlData * pData = new ControlData;
          pData->direction = p_Drivetrain->STOP;
          p_Drivetrain->moveFunction(pData);
        }
      break;
    }
  }
}
