#include "Encoder.h"

#define IN_1 2
#define IN_2 3

Encoder leftEncoder;
Encoder rightEncoder;
void leftInterruptFunc();
void rightInterruptFunc();

//interrupt function
void leftInterruptFunc() {
    if(digitalRead(leftEncoder.INT_PIN)){
      leftEncoder.rise();
    } else {
      leftEncoder.fall();
    }
}

//interrupt function
void rightInterruptFunc() {
    if(digitalRead(rightEncoder.INT_PIN)){
      rightEncoder.rise();
    } else {
      rightEncoder.fall();
    }
}

double leftLastSpeed  = leftEncoder.speed;
double rightLastSpeed = rightEncoder.speed;


void setup(){
  //declare encoder object
  leftEncoder.INT_PIN = IN_1;
  leftEncoder.begin(0.0250);
  rightEncoder.INT_PIN = IN_2;
  rightEncoder.begin(0.0250);

  //attach interrupt to INT_PIN
  attachInterrupt(digitalPinToInterrupt(leftEncoder.INT_PIN), leftInterruptFunc, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightEncoder.INT_PIN), rightInterruptFunc, CHANGE);

  //begin serial monitor
  Serial.begin(9600);
}

void loop() {
  if(leftEncoder.speed != leftLastSpeed){
    Serial.println(leftEncoder.speed);
    leftLastSpeed = leftEncoder.speed;
  }
  if(rightEncoder.speed != rightLastSpeed){
    Serial.println(rightEncoder.speed);
    rightLastSpeed = rightEncoder.speed;
  }
}





