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
  for(int i = 0; i <= 255; i++){
    ControlData * data = new ControlData;
    data->direction = base.FWD;
    data->speed = i;
    base.moveFunction(data);
    if ((millis() - pollTime) >= 100){
      Serial.print(float(base.leftEncoder.count)/9.55);
      base.leftEncoder.count = 0;
      Serial.print(" ");
      Serial.println(float(base.rightEncoder.count)/95.5);
      base.rightEncoder.count = 0;
      pollTime = millis();
    }
  }
}





