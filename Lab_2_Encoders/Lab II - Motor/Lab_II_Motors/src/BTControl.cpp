/*
Define a set of functions from the BT control header
*/
#include "BTControl.h"
#include "Drivetrain.h"

Bluetooth::Bluetooth(){
    pinMode(BT_RX, INPUT);
    pinMode(BT_TX, OUTPUT);
    Serial1.begin(9600);
}

ControlData * Bluetooth::BTPoll() {
    if(Serial1.available()){
        char buffer = (char)Serial1.read();
        ControlData * pData;
        switch (buffer) {
        case 'w':
            pData->direction = Drivetrain::FWD;
            pData->speed     = 100;
        break;
        case 'a':
            pData->direction = Drivetrain::LEFT;
            pData->speed     = 100;
        break;
        case 's':
            pData->direction = Drivetrain::BACK;
            pData->speed     = 100;
        break;
        case 'd':
            pData->direction = Drivetrain::RIGHT;
            pData->speed     = 100;
        break;
        default:
            pData = NULL;
        break;
        }
        return pData;
    } else 
        return NULL;
}
