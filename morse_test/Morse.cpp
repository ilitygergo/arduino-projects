#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pinNumber, int milliseconds)
{
  pinMode(pinNumber, OUTPUT);
  pin = pinNumber;
  interval = milliseconds;
}

void Morse::dot()
{
  digitalWrite(pin, HIGH);
  delay(interval);
  digitalWrite(pin, LOW);
  delay(interval);
}

void Morse::dash()
{
  digitalWrite(pin, HIGH);
  delay(interval * 3);
  digitalWrite(pin, LOW);
  delay(interval);
}

void Morse::convertStringToMorseCode(char* word)
{
  Serial.print("convert function");
  delay(1000);
}

void Morse::convertCharToMorseCode()
{
  delay(1000);
}

void Morse::convertBinaryToMorseCode()
{
  delay(1000);
}
