const byte rxPin = 15;
const byte txPin = 14;

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.print("Initializing");
}

void loop() {
  
  if(Serial1.available())
  {
    char buf = (char)Serial1.read();
    Serial.print(buf);
    Serial.print("\n");
    switch(buf){
      case('1'): Serial.print("action1\n"); break;
      case('2'): Serial.print("action2\n"); break;
      case('3'): Serial.print("action3\n"); break;
      case('4'): Serial.print("action4\n"); break;
      case('5'): Serial.print("action5\n"); break;
      case('6'): Serial.print("action6\n"); break;
      case('7'): Serial.print("action7\n"); break;
      case('8'): Serial.print("action8\n"); break;
      case('9'): Serial.print("action9\n"); break;
      default: Serial.print("invalid action\n");
    }
  }
//  if(Serial.available())
//  {
//    Serial1.print((char)Serial.read());
//  }
}
