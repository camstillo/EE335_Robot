//#include "Encoder.h"
#include "Drivetrain.h"
// #include "BTControl.h"
// #include "Encoder.h"
// #include "LineFollow.h"
// #include "Gripper.h"
#include <Arduino.h>
#include "Ultrasonic.h"

//Declare objects
Drivetrain base;
// Gripper frontGrip;
Ultrasonic frontSensor;

unsigned long pollTime = millis();
uint8_t n = 0;

#define TRIG_PIN 7
#define ECHO_PIN 6

void setup(){
  //initalize drivetrain
  base.begin();

  //initialize ultrasonic
  frontSensor.begin();

  //begin serial monitor
  Serial.begin(115200);
}

void loop() {
  ControlData * pData = new ControlData;
  pData->direction = base.FWD;
  pData->speed     = 100;
  base.moveFunction(pData);
} 





