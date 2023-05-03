//#include "Encoder.h"
#include "Motor.h"

#define IN_1 2
#define IN_2 3

//delcare encoder objects and their interrupt functions
// Encoder leftEncoder;
// Encoder rightEncoder;
// void leftInterruptFunc();
// void rightInterruptFunc();

//declare motor objects
Motor frontRight;
Motor frontLeft;
Motor backRight;
Motor backLeft;

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
  frontRight.begin(4);
  frontLeft.begin(2);
  backRight.begin(3);
  backLeft.begin(1);

  //begin serial monitor
  Serial.begin(9600);
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

  
  if(millis() <= 10000){
    MotorData* data1 = new MotorData;
    data1->speed = 100;
    frontRight.speedSet(data1);
    MotorData* data2 = new MotorData;
    data2->speed = 100;
    frontLeft.speedSet(data2);
    MotorData* data3 = new MotorData;
    data3->speed = 100;
    backLeft.speedSet(data3);
    MotorData* data4 = new MotorData;
    data4->speed = 100;
    backRight.speedSet(data4);
  } else {
    frontRight.halt();
    frontLeft.halt();
    backLeft.halt();
    backRight.halt();
  }

}





