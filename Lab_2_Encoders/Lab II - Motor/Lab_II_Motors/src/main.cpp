//#include "Encoder.h"
// #include "Motor.h"
#include "Drivetrain.h"
#include "BTControl.h"

#define IN_1 2
#define IN_2 3

//delcare encoder objects and their interrupt functions
// Encoder leftEncoder;
// Encoder rightEncoder;
// void leftInterruptFunc();
// void rightInterruptFunc();

//declare motor objects
// Motor frontRight;
// Motor frontLeft;
// Motor backRight;
// Motor backLeft;

//Declare Drivetrain object
Drivetrain base;
Bluetooth BT;

// //interrupt function
// void leftInterruptFunc() {
//     if(digitalRead(leftEncoder.INT_PIN)){
//       leftEncoder.rise();
//     } else {
//       leftEncoder.fall();
//     }
// }

// //interrupt function
// void rightInterruptFunc() {
//     if(digitalRead(rightEncoder.INT_PIN)){
//       rightEncoder.rise();
//     } else {
//       rightEncoder.fall();
//     }
// }

// //global variables for speed detection
// double leftLastSpeed  = leftEncoder.speed;
// double rightLastSpeed = rightEncoder.speed;

void setup(){
  // //initialize left encoders
  // leftEncoder.INT_PIN = IN_1;
  // leftEncoder.begin(0.0250);
  // rightEncoder.INT_PIN = IN_2;
  // rightEncoder.begin(0.0250);

  //attach interrupt to INT_PIN
  // attachInterrupt(digitalPinToInterrupt(leftEncoder.INT_PIN), leftInterruptFunc, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(rightEncoder.INT_PIN), rightInterruptFunc, CHANGE);

  //initialize motor object
  // frontRight.begin(4);
  // frontLeft.begin(2);
  // backRight.begin(3);
  // backLeft.begin(1);

  //initalize drivetrain
  base.begin();

  //begin serial monitor
  // Serial.begin(9600);
}

void loop() {
  // static unsigned long lastTime = millis();
  // if (millis() - lastTime > 1000){
    // lastTime = millis();
  // }
  // if(leftEncoder.speed != leftLastSpeed){
  //   Serial.println(leftEncoder.speed);
  //   leftLastSpeed = leftEncoder.speed;
  // }
  // if(rightEncoder.speed != rightLastSpeed){
  //   Serial.println(rightEncoder.speed);
  //   rightLastSpeed = rightEncoder.speed;
  // }
  ControlData * pData = new ControlData;
  if(Serial1.available()){
        char buffer = (char)Serial1.read();
        // ControlData * pData = new ControlData;
        switch (buffer) {
        case 0x64:
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
    } else 
      pData = NULL;
  // Data = BT.BTPoll();
  base.moveFunction(pData);
  
  // if(millis() <= 2000){
    // MotorData* data1 = new MotorData;
    // data1->speed = 100;
    // frontRight.speedSet(data1);
    // MotorData* data2 = new MotorData;
    // data2->speed = 100;
    // frontLeft.speedSet(data2);
    // MotorData* data3 = new MotorData;
    // data3->speed = 100;
    // backLeft.speedSet(data3);
    // MotorData* data4 = new MotorData;
    // data4->speed = 100;
    // backRight.speedSet(data4);
    // if(millis() <= 1000){
    //   ControlData * cData = new ControlData;
    //   cData->direction = base.FWD;
    //   cData->speed = 100;
    //   base.moveFunction(cData);
    // } else if (millis() > 1000 && millis() <= 2000){
    //   ControlData * cData = new ControlData;
    //   cData->direction = base.BACK;
    //   cData->speed = 100;
    //   base.moveFunction(cData);
    // } else if (millis() > 2000 && millis() <= 3000){
    //   ControlData * cData = new ControlData;
    //   cData->direction = base.RIGHT;
    //   cData->speed = 100;
    //   base.moveFunction(cData);
    // } else if (millis() > 3000 && millis() <= 4000){
    //   ControlData * cData = new ControlData;
    //   cData->direction = base.LEFT;
    //   cData->speed = 100;
    //   base.moveFunction(cData);
    // } else {
    //   ControlData * cData = new ControlData;
    //   cData->direction = base.STOP;
    //   cData->speed = 0;
    //   base.moveFunction(cData);
    // }

  // } else {
  //   // frontRight.halt();
  //   // frontLeft.halt();
  //   // backLeft.halt();
  //   // backRight.halt();
    
  // }

}





