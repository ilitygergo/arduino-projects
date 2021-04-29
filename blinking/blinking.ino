#define interval 2000
#define LEDPin 13

void setup() {
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  SosSignal();
}

void SosSignal(){
  quickLedSignals(3);
  longLedSignals(3);
  quickLedSignals(3);

  delay(interval);
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
