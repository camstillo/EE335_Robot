/*
This library defines a set of functions which will take a continuous stream of input from the BT module
and output a stream of data which is fed into the drivetrain class. This header just takes in the stream
of data and passes that data to a ControlData object which it creates each time. This also doesn't focus 
on creating the BT stream, but instead to just read it in
*/
#ifndef _BTCONTROL_H
#define _BTCONTROL_H
#include "Drivetrain.h"
#include "Gripper.h"
#include "LineFollow.h"

#define BT_TX 14
#define BT_RX 15

class Bluetooth {
    //drivetrain and gripper pointers
    Drivetrain * p_Drivetrain;
    Gripper * p_Gripper;

    //send movement information for bluetooth signal
    void BTCommand(uint8_t);

    public:
    //Constructor
    Bluetooth(Drivetrain*, Gripper*);

    //wait for bluetooth signal
    void BT_Poll();
};


#endif