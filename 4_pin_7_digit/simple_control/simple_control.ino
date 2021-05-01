/**
 * 2021.05.01.
 * REQUIREMENTS: 4 dogot 7 pin display
 */

#include "SevSeg.h"

SevSeg sevseg;
const int buzzer = 1;
const int buttonPin = A0;
int countdown = 10;
int buttonState = 0;

void setup(){
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT);
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelays = false;
  bool leadingZeros = true;
  bool disableDecPoint = false;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(100);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() - timer >= 100) {
  if (buttonState == HIGH) {
    tone(buzzer, 1000);
    deciSeconds=0;
  } else {
    noTone(buzzer);
    timer += 100;
    deciSeconds++;
  }
  
    sevseg.setNumber(deciSeconds, 1);
  }

  sevseg.refreshDisplay();
}
