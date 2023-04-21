#ifndef _STATE_H
#define _STATE_H
#endif

class state {
  public:
  virtual ~state(){}
  virtual void enter(){};
  virtual state* run() = 0;
};

