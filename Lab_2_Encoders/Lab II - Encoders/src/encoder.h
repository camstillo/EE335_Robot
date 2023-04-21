#include "state.h"
#include <Arduino.h>

class encoder{
    public:

    //encoder variables 
    static uint8_t PIN;
    static volatile bool intFlag;
    static volatile int count;
    static unsigned long startTime;
    static unsigned long pulseWidth;    

    //initialization function
    void begin(uint8_t intPin, uint8_t ledPin);

    private:
    //function called during interrupt
    static void interruptFlag();

    //glue functions to redirect interrupt
    //handling routines
    static encoder * instances [2];
    static void switchPressedExt0 (); 
    static void switchPressedExt1 ();
};

class low: public state {
  public:
  virtual void enter() override;
  virtual state* run() override;
};

class rising: public state {
  public:
  virtual void enter() override;
  virtual state* run() override;
};

class high: public state {
  public:
  virtual void enter() override;
  virtual state* run() override;
};

class falling: public state {
  public:
  virtual void enter() override;
  virtual state* run() override;
};

//instantiate all the state objects
static low Low;
static high High;
static falling Fall;
static rising Rise;

