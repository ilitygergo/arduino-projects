/**
 * 2021.05.01.
 * REQUIREMENTS:
 * - 4 dogot 7 pin display
 * - button
 * - buzzer
 */
#include <SevSeg.h>

#define BUZZER_PIN A1
#define BUTTON_PIN A0
#define STUDY_MINUTES 40
#define REST_MINUTES 15

SevSeg sevseg;
int buttonState;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  initFourDigitDisplay();
}

void initFourDigitDisplay() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelays = false;
  bool leadingZeros = true;
  bool disableDecPoint = false;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);
}

void loop() {
  countdownMinutesUntilButtonPushed(STUDY_MINUTES);
  countdownMinutesUntilButtonPushed(REST_MINUTES);
}

void countdownMinutesUntilButtonPushed(int minutes) {
  int seconds = minutes * 60;
  buttonState = LOW;

  while (buttonState != HIGH && seconds >= 0) {
    waitSecondsWithDisplayRefresh(1);
    sevseg.setNumber(secondsToHourTime(seconds--), 2);
  }

  if (seconds < 0) {
    finishedBuzzingUntilButtonPushed();
    waitSecondsWithDisplayRefresh(1);
    return;
  }

  stopBeforeFinish();
}

void finishedBuzzingUntilButtonPushed() {
  sevseg.setChars("DONE");
  buttonState = LOW;
  tone(BUZZER_PIN, 1046);

  while (buttonState != HIGH) {
    buttonState = digitalRead(BUTTON_PIN);
    waitSecondsWithDisplayRefresh(1);
  }

  noTone(BUZZER_PIN);
}

int secondsToHourTime(int seconds) {
  int minutes = seconds / 60;
  seconds = seconds % 60;
  return (minutes * 100) + seconds;
}

void waitSecondsWithDisplayRefresh(int seconds) {
  seconds = seconds * 10;

  while (seconds > 0) {
    static unsigned long timer = millis();

    if (buttonState == LOW)
      buttonState = digitalRead(BUTTON_PIN);

    if (millis() - timer >= 100) {
        timer += 100;
        seconds--;
    }

    sevseg.refreshDisplay();
  }
}

void stopBeforeFinish() {
  sevseg.setChars("STOP");
  waitSecondsWithDisplayRefresh(2);
  buttonState = LOW;
}
