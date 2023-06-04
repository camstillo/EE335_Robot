//#include "Encoder.h"
#include "Drivetrain.h"
// #include "BTControl.h"
// #include "Encoder.h"
#include "LineFollow.h"
// #include "Gripper.h"
#include <Arduino.h>
// #include "Ultrasonic.h"

//Declare objects
Drivetrain base;
// Gripper frontGrip;
// Ultrasonic frontSensor;

// void handlerFunc1(){
//   base.leftInterruptFunc();
// }

// void handlerFunc2(){
//   base.rightInterruptFunc();
// }

// void handlerFunc3(){
//   leftInterrupt();
// }

// void handlerFunc4(){
//   rightInterrupt();
// }

unsigned long pollTime = millis();
uint8_t n = 0;

void setup(){
  //initalize drivetrain
  base.begin();
  // attachInterrupt Functions to Encoders
  // attachInterrupt(digitalPinToInterrupt(IN_1), handlerFunc1, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(IN_2), handlerFunc2, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(L_LF), handlerFunc3, RISING);
  // attachInterrupt(digitalPinToInterrupt(R_LF), handlerFunc4, RISING);

  //begin serial monitor
  Serial.begin(115200);
}

void loop() {
  while(n < 1){
    LineFollow LF_base = LineFollow(&base);
    LF_base.follow();
    delete &LF_base;
    n++;
  }
}





