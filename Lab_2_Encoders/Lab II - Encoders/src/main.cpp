#include <Arduino.h>
#include "encoder.h"

#define IN_1    3
#define OUT_1   5
#define IN_2    2
#define OUT_2   4

int main(){
  //intialize pins
  pinMode(IN_1, INPUT);
  pinMode(IN_2, INPUT);
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);

  //initialize left encoder object
  static encoder leftEncoder;
  leftEncoder.begin(IN_1);
  bool leftStateChange = LOW;
  state* leftState = &Low;
  state* leftPrevState = leftState;

  //initialize right encoder object
  static encoder rightEncoder;
  rightEncoder.begin(IN_2);
  bool rightStateChange = LOW;
  state* rightState = &Low;
  state* rightPrevState = rightState;

  while(1){
    //if either the state has changed, 
    //run the state entrance procedure
    if(leftStateChange){
      leftState->enter();
    } else if(rightStateChange) {
      rightState->enter();
    }

    //otherwise, continually run the 
    //run operation for each state
    leftState = leftPrevState->run();
    rightState = rightPrevState->run();

    //check to see if run changed the states at all
    rightStateChange = (rightState != rightPrevState);
    leftStateChange = (leftState != leftPrevState);

    //update previous state
    rightPrevState = rightState;
    leftPrevState  = leftState;
  }
}