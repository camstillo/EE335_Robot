#include "state.h"
#include <Arduino.h>

class encoder{
    public:
    static const uint8_t PIN;
    static volatile int count;
    static unsigned long startTime;
    static unsigned long pulseWidth;
    static bool intFlag;
    void begin(uint8_t pinNumber);
    void interruptFlag();
    
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