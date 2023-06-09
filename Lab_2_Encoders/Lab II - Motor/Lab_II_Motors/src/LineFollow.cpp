/*
Describes the functions declared in the LineFollow.h file
*/
#include "LineFollow.h"

LineFollow::LineFollow(Drivetrain * p_Drivetrain){
    p_dTrain = p_Drivetrain;
}

void LineFollow::follow(){
    while(!endOfLine){
        if(digitalRead(R_LF) && digitalRead(L_LF)) this->stop();
        else if(digitalRead(L_LF)) {
            this->leftInterrupt();
        }
        else if(digitalRead(R_LF)) {
            this->rightInterrupt();
        }
        else this->run();
    } return;
}

void LineFollow::run(){
    ControlData * pData = new ControlData;
    pData->direction = p_dTrain->FWD;
    pData->speed = 100;
    p_dTrain->moveFunction(pData);
}

void LineFollow::leftInterrupt(){
    ControlData * pData = new ControlData;
    pData->direction = p_dTrain->LEFT;
    pData->speed = 100;
    p_dTrain->moveFunction(pData);
}

void LineFollow::rightInterrupt(){
    ControlData * pData = new ControlData;
    pData->direction = p_dTrain->RIGHT;
    pData->speed = 100;
    p_dTrain->moveFunction(pData);
}

void LineFollow::stop(){
    ControlData * pData = new ControlData;
    pData->direction = p_dTrain->STOP;
    p_dTrain->moveFunction(pData);
    endOfLine = 1;
}