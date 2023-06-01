//#include "Encoder.h"
// #include "Drivetrain.h"
// #include "BTControl.h"
// #include "Encoder.h"
// #include "LineFollow.h"
// #include "Gripper.h"
#include "Arduino.h"
#include "Ultrasonic.h"

//Declare objects
//Drivetrain base;
// LineFollow base;
// Gripper frontGrip;
Ultrasonic frontSensor;

void handlerFunc1(){
  // base.LF_Base.leftInterruptFunc();
}

void handlerFunc2(){
//  base.LF_Base.rightInterruptFunc();
}

void handlerFunc3(){
  // Serial.println("1");
  // base.rightTrig();
  
}

void handlerFunc4(){
  // Serial.println("2");
  // base.leftTrig();
  
}

unsigned long pollTime = millis();

void setup(){
  //initalize drivetrain
  // base.begin();

  //attachInterrupt Functions to Encoders
//  attachInterrupt(digitalPinToInterrupt(IN_1), handlerFunc1, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(IN_2), handlerFunc2, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(R_LF), handlerFunc3, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(L_LF), handlerFunc4, CHANGE);

  // frontGrip.begin(SERVO_PIN);

  //begin serial monitor
  Serial.begin(115200);
}

void loop() {
    if ((millis() - pollTime) >= 2500){
      // frontGrip.changeState();
      //Serial.println(frontGrip.m_angle);
      digitalWrite(TRIG_PIN, LOW);
      frontSensor.trigReq();
      // Serial.println(frontSensor.distance);
    //   Serial.print(float(base.leftEncoder.count)/0.0764);
    //   base.leftEncoder.count = 0;
    //   Serial.print(" ");
    //   Serial.println(float(base.rightEncoder.count)/0.0764);
    //   base.rightEncoder.count = 0;
    //   pollTime = millis();
    // }
      pollTime = millis();
    }
}





