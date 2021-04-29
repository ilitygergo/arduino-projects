#define interval 2000
#define pause 350
#define LEDPin 13

void setup() {
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  helloWorld();
  delay(interval);
}

void helloWorld(){
  quickLedSignals(4);
  delay(pause);

  quickLedSignals(1);
  delay(pause);

  quickLedSignals(1);
  longLedSignals(1);
  quickLedSignals(2);
  delay(pause);

  quickLedSignals(1);
  longLedSignals(1);
  quickLedSignals(2);
  delay(pause);

  longLedSignals(3);
  delay(pause);

  quickLedSignals(1);
  longLedSignals(2);
  delay(pause);

  longLedSignals(3);
  delay(pause);

  quickLedSignals(1);
  longLedSignals(1);
  quickLedSignals(1);
  delay(pause);

  quickLedSignals(1);
  longLedSignals(1);
  quickLedSignals(2);
  delay(pause);

  longLedSignals(1);
  quickLedSignals(2);
}

void quickLedSignals(int x) {
  for (int i = 0; i < x; i++) {
    digitalWrite(LEDPin, HIGH);
    delay(200);
    digitalWrite(LEDPin, LOW);
    delay(200);
  }
}

void longLedSignals(int x) {
  for (int i = 0; i < x; i++) {
    digitalWrite(LEDPin, HIGH);
    delay(800);
    digitalWrite(LEDPin, LOW);
    delay(200);
  }
}
