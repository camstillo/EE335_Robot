//#include "Encoder.h"
#include "Drivetrain.h"
// #include "BTControl.h"
#include "Encoder.h"

//Declare objects
Drivetrain base;

void handlerFunc1(){
  base.leftInterruptFunc();
}

void handlerFunc2(){
  base.rightInterruptFunc();
}

unsigned long pollTime = millis();

void setup(){
  //initalize drivetrain
  base.begin();

  //attachInterrupt Functions to Encoders
  attachInterrupt(digitalPinToInterrupt(IN_1), handlerFunc1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(IN_2), handlerFunc2, CHANGE);

  //begin serial monitor
  Serial.begin(115200);
}

void loop() {
  // for(float i = 0; i <= 2; i+0.5){
    ControlData * data = new ControlData;
    data->direction = base.FWD;
    data->speed = 1.3;
    base.moveFunction(data);
    if ((millis() - pollTime) >= 100){
      Serial.print(float(base.leftEncoder.count)/0.0764);
      base.leftEncoder.count = 0;
      Serial.print(" ");
      Serial.println(float(base.rightEncoder.count)/0.0764);
      base.rightEncoder.count = 0;
      pollTime = millis();
    }
  //}
}





