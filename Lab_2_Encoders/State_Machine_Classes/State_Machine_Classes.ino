class state {
  public:
  virtual ~state(){}
  virtual void enter(){};
  virtual state* run() = 0;
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

void setup(){}
void loop(){}
