#include "Drivetrain.h"
#include "BTControl.h"
#include "LineFollow.h"
#include "Gripper.h"
#include <Arduino.h>

//Declare objects
Drivetrain base;
Gripper frontGrip;
Bluetooth BT_Ctrl = Bluetooth(&base, &frontGrip);

void setup(){
  //initialize objects
  base.begin();
  frontGrip.begin(SERVO_PIN);
  
  //begin serial monitor
  Serial.begin(115200);
}

void loop() {
  BT_Ctrl.BT_Poll();
} 





