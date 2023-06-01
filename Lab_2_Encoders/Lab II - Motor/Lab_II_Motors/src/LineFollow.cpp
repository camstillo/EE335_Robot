/*
Describes the functions declared in the LineFollow.h file
*/
#include "lineFollow.h"

void LineFollow::begin(){
    LF_Base.begin();
    InternalEvent(ST_RUN);
}

void LineFollow::leftTrig(){
    if(digitalRead(R_LF)) InternalEvent(ST_IDLE);
    BEGIN_TRANSITION_MAP
        TRANSITION_MAP_ENTRY(ST_L_TRIG)     //ST_Run
        TRANSITION_MAP_ENTRY(ST_L_TRIG)     //ST_L_Trig
        TRANSITION_MAP_ENTRY(ST_L_TRIG)     //ST_R_Trig
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN) //ST_IDLE
    END_TRANSITION_MAP(NULL)
}

void LineFollow::rightTrig(){
    if(digitalRead(L_LF)) InternalEvent(ST_IDLE);
    BEGIN_TRANSITION_MAP
        TRANSITION_MAP_ENTRY(ST_R_TRIG)     //ST_Run
        TRANSITION_MAP_ENTRY(ST_R_TRIG)     //ST_L_Trig
        TRANSITION_MAP_ENTRY(ST_R_TRIG)     //ST_R_Trig
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN) //ST_IDLE
    END_TRANSITION_MAP(NULL)
}

void LineFollow::ST_Run(){
    ControlData * pData = new ControlData;
    pData->direction = LF_Base.FWD;
    pData->speed = 100;
    LF_Base.moveFunction(pData);
}

void LineFollow::ST_L_Trig(){
    //turn the robot until the sensor doesn't see the line anymore
    while(digitalRead(L_LF)){
        ControlData * pData = new ControlData;
        pData->direction = LF_Base.LEFT;
        pData->speed = 30;
        LF_Base.moveFunction(pData);
    }
    InternalEvent(ST_RUN);
}

void LineFollow::ST_R_Trig(){
    //turn the robot until the sensor doesn't see the line anymore
    while(digitalRead(R_LF)){
        ControlData * pData = new ControlData;
        pData->direction = LF_Base.LEFT;
        pData->speed = 30;
        LF_Base.moveFunction(pData);
    }
    InternalEvent(ST_RUN);
}

void LineFollow::ST_Idle(){
    ControlData * pData = new ControlData;
    pData->direction = LF_Base.STOP;
    LF_Base.moveFunction(pData);
}
