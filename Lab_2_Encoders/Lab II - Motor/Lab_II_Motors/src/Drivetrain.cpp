/*
Define the set of functions inside the Drivetrain header file.
*/
#include "Drivetrain.h"

void Drivetrain::begin(){
    FrontRight.begin(FRONT_RIGHT);
    FrontLeft.begin(FRONT_LEFT);
    BackRight.begin(BACK_RIGHT);
    BackLeft.begin(BACK_LEFT);
}

void Drivetrain::moveFunction(ControlData * pData){
    switch (pData->direction) {
    case STOP:
        ExternalEvent(ST_IDLE);
    break;
    case FWD:
        ExternalEvent(ST_FORWARD, pData);
    break;
    case BACK:
        ExternalEvent(ST_BACKWARD, pData);
    break;
    case RIGHT:
        ExternalEvent(ST_RIGHT, pData);
    break;
    case LEFT:
        ExternalEvent(ST_LEFT, pData);
    break;
    default:
        ExternalEvent(ST_IDLE);
    break;
    }
}

void Drivetrain::ST_Idle(){
    FrontRight.halt();
    FrontLeft.halt();
    BackRight.halt();
    BackLeft.halt();
}

void Drivetrain::ST_Forward (ControlData * pData){
    MotorData* data = new MotorData;
    data->speed = pData->speed;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = pData->speed;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = pData->speed;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = pData->speed;
    BackLeft.speedSet(data3);

    InternalEvent(ST_IDLE);
}

void Drivetrain::ST_Backward(ControlData * pData){
    MotorData* data = new MotorData;
    data->speed = -1*pData->speed;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = -1*pData->speed;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = -1*pData->speed;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = -1*pData->speed;
    BackLeft.speedSet(data3);

    InternalEvent(ST_IDLE);
}

void Drivetrain::ST_Left    (ControlData * pData){
    MotorData* data = new MotorData;
    data->speed = pData->speed;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = -1*pData->speed;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = pData->speed;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = -1*pData->speed;
    BackLeft.speedSet(data3);

    InternalEvent(ST_IDLE);
}

void Drivetrain::ST_Right   (ControlData * pData){
    MotorData* data = new MotorData;
    data->speed = -1*pData->speed;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = pData->speed;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = -1*pData->speed;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = pData->speed;
    BackLeft.speedSet(data3);

    InternalEvent(ST_IDLE);
}
