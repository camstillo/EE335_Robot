// input 1: pin 3
// input 2: pin 2
// output 1: pin 5
// output 2: pin 4
#define IN_1    3
#define OUT_1   5
#define IN_2    2
#define OUT_2   4

volatile bool state1 = LOW;
volatile bool state2 = LOW;
volatile long time1 = 0;
volatile long time2 = 0;
volatile long lastTime = 0;
volatile long pulseWidth1 = 0;
volatile long pulseWidth2 = 0;

void setup() {
  pinMode(IN_1, INPUT);
  pinMode(IN_2, INPUT);
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(IN_1), stateChange1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(IN_2), stateChange2, RISING);
  Serial.begin(115200);
}

void loop() {

  if(state1){
    digitalWrite(OUT_1, HIGH);
    Serial.println("state1");
  } else {
    digitalWrite(OUT_1, LOW);
    Serial.println("off1");
  }
  if (state2) {
    digitalWrite(OUT_2, HIGH);
    Serial.println("state2");
  } else {
    digitalWrite(OUT_2, LOW);
    Serial.println("off2");
  }
  Serial.println(pulseWidth1);
  Serial.println(pulseWidth2);
}

void stateChange1(){
  state1 = !state1;
}

void stateChange2(){
  state2 = !state2;
  pulseWidth2 = millis() - time2;
  //time2 = millis();
}
