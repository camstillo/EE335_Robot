#include "state.h"
#include <Arduino.h>

class encoder{
    public:

    //encoder variables 
    uint8_t PIN;
    volatile bool intFlag;
    volatile int count;
    unsigned long startTime;
    unsigned long pulseWidth;    

    //initialization function
    void begin(uint8_t intPin, uint8_t ledPin);

    friend class low;
    friend class high;
    friend class rising;
    friend class falling;

    private:
    //function called during interrupt
    void interruptFlag();

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

