/*
Define the set of functions inside the Drivetrain header file.
*/
#include "Drivetrain.h"

void Drivetrain::leftInterruptFunc(){
    if(digitalRead(leftEncoder.INT_PIN)){
      leftEncoder.rise();
    } else {
      leftEncoder.fall();
    }
}
void Drivetrain::rightInterruptFunc(){
    if(digitalRead(rightEncoder.INT_PIN)){
        rightEncoder.rise();
    } else {
        rightEncoder.fall();
    }
}

int8_t Drivetrain::calcInputPID(float setSpeed, uint32_t encPulseCount){
    if((millis() - Drivetrain::lastTime) >= 200){ //if 100ms or more have passed since last measurement
        //calc setSpeed in pulses/sec
        float _setSpeed = setSpeed * 95.5; //m/s to pulses/s
        //calc encoder count value
        float _actSpeed = float(encPulseCount)/Drivetrain::f_timeInterval; //number of pulses in *approx.* 100ms
        //calculate error
        int8_t error = int8_t(_setSpeed/f_pulsePerSecPerBit) - //give an error in bit value between 0-250
                        int8_t(_actSpeed/f_pulsePerSecPerBit);     
        //calculate motor driving value
        int8_t newPIDVal = 
            (K_P*error) + 
            (K_I*(Drivetrain::intSum + error)*Drivetrain::f_timeInterval) +
            (K_D*((error - Drivetrain::lastError)/Drivetrain::f_timeInterval));
        //set the last value = new value
        //set last error value
        Drivetrain::lastPIDVal = newPIDVal;
        Drivetrain::lastError = error;
        //reset counter
        Drivetrain::lastTime = 0;
        //check if number of times through the loop is too much and need to reset integral
        Drivetrain::intWindupCount++;
        if(Drivetrain::intWindupCount > 10){
            Drivetrain::intSum = 0;
            Drivetrain::intWindupCount = 0;
        }
        //return new value
        return newPIDVal;
    
    } else 
        return lastPIDVal;
    
}

void Drivetrain::begin(){
    //initialize motors
    FrontRight.begin(FRONT_RIGHT);
    FrontLeft.begin(FRONT_LEFT);
    BackRight.begin(BACK_RIGHT);
    BackLeft.begin(BACK_LEFT);

    //initalize encoder objects
    leftEncoder.INT_PIN = IN_1;
    rightEncoder.INT_PIN = IN_2;
    leftEncoder.begin();
    rightEncoder.begin();
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
    // uint8_t r_SpeedPID = calcInputPID(pData->speed, Drivetrain::rightEncoder.count);
    // uint8_t l_SpeedPID = calcInputPID(pData->speed, Drivetrain::leftEncoder.count);
    uint8_t r_SpeedPID = pData->speed;
    uint8_t l_SpeedPID = pData->speed;
    MotorData* data = new MotorData;
    data->speed = r_SpeedPID;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = l_SpeedPID;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = r_SpeedPID;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = l_SpeedPID;
    BackLeft.speedSet(data3);

    // InternalEvent(ST_IDLE);
}

void Drivetrain::ST_Backward(ControlData * pData){
    //uint8_t r_SpeedPID = calcInputPID(pData->speed, Drivetrain::rightEncoder.count);
    //uint8_t l_SpeedPID = calcInputPID(pData->speed, Drivetrain::leftEncoder.count);
    uint8_t r_SpeedPID = pData->speed;
    uint8_t l_SpeedPID = pData->speed;
    MotorData* data = new MotorData;
    data->speed = -1*r_SpeedPID;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = -1*l_SpeedPID;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = -1*r_SpeedPID;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = -1*l_SpeedPID;
    BackLeft.speedSet(data3);

    // InternalEvent(ST_IDLE);
}

void Drivetrain::ST_Left    (ControlData * pData){
    // uint8_t r_SpeedPID = calcInputPID(pData->speed, Drivetrain::rightEncoder.count);
    // uint8_t l_SpeedPID = calcInputPID(pData->speed, Drivetrain::leftEncoder.count);
    uint8_t r_SpeedPID = pData->speed;
    uint8_t l_SpeedPID = pData->speed;
    MotorData* data = new MotorData;
    data->speed = r_SpeedPID;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = -1*l_SpeedPID;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = r_SpeedPID;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = -1*l_SpeedPID;
    BackLeft.speedSet(data3);

    // InternalEvent(ST_IDLE);
}

void Drivetrain::ST_Right   (ControlData * pData){
    // uint8_t r_SpeedPID = calcInputPID(pData->speed, Drivetrain::rightEncoder.count);
    // uint8_t l_SpeedPID = calcInputPID(pData->speed, Drivetrain::leftEncoder.count);
    uint8_t r_SpeedPID = pData->speed;
    uint8_t l_SpeedPID = pData->speed;
    MotorData* data = new MotorData;
    data->speed = -1*r_SpeedPID;
    FrontRight.speedSet(data);
    MotorData* data1 = new MotorData;
    data1->speed = l_SpeedPID;
    FrontLeft.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = -1*r_SpeedPID;
    BackRight.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = l_SpeedPID;
    BackLeft.speedSet(data3);

    // InternalEvent(ST_IDLE);
}
