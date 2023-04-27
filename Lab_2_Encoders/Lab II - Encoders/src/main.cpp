#include <Arduino.h>
#include "encoder.h"
// #include "avr8-stub.h"
// #include "app_api.h"

#define IN_1    3
#define OUT_1   5
#define IN_2    2
#define OUT_2   4

int main(){
  //initialize debugger
  // debug_init();  

  //initialize left encoder object
  encoder leftEncoder;
  leftEncoder.begin(IN_1, OUT_1);
  bool leftStateChange = LOW;
  state* leftState = &Low;
  state* leftPrevState = leftState;

  //initialize right encoder object
  encoder rightEncoder;
  rightEncoder.begin(IN_2, OUT_2);
  bool rightStateChange = LOW;
  state* rightState = &Low;
  state* rightPrevState = rightState;

  //Serial.begin(9600);

  while(1){
    //if either the state has changed, 
    //run the state entrance procedure
    if(leftStateChange){
      leftState->enter();
      //Serial.println("left change");
    } else if(rightStateChange) {
      rightState->enter();
      //Serial.println("right change");
    }

    //otherwise, continually run the 
    //run operation for each state
    leftState = leftPrevState->run();
    rightState = rightPrevState->run();

    //check to see if run changed the states at all
    rightStateChange = (rightState != rightPrevState);
    leftStateChange = (leftState != leftPrevState);
    //Serial.println(rightStateChange);

    //update previous state
    rightPrevState = rightState;
    leftPrevState  = leftState;
  }
}