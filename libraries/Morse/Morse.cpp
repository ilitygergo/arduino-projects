#include "Arduino.h"
#include "Morse.h"

enum class CharacterBinaryCode
{
  // 0 - short, 1 - long
  a = "01", b = "1000", c = "1010", d = "100", e = "0", f = "0010",
  g = "110", h = "0000", i = "00", j = "0111", k = "101", l = "0100",
  m = "11", n = "10", o = "111", p = "0110", q = "1101", r = "010",
  s = "000", t = "1", u = "001", v = "0001", w = "011", x = "1001",
  y = "1011", z = "1100", 1 = "01111", 2 = "00111", 3 = "00011", 4 = "00001",
  5 = "00000", 6 = "10000", 7 = "11000", 8 = "11100", 9 = "11110", 0 = "11111"
}

Morse::Morse(int pinNumber, int timeUnit)
{
  pinMode(pinNumber, OUTPUT);
  pinNumber = pinNumber;
  dotSpan = timeUnit;
  dashSpan = timeUnit * 3;
  betweenSameLettersPause = timeUnit;
  betweenLettersPause = timeUnit * 3;
  betweenWordsPause = timeUnit * 7;
}

void Morse::dot()
{
  digitalWrite(pinNumber, HIGH);
  delay(dotSpan);
  digitalWrite(pinNumber, LOW);
  delay(betweenLettersPause);
}

void Morse::dash()
{
  digitalWrite(pinNumber, HIGH);
  delay(dashSpan);
  digitalWrite(pinNumber, LOW);
  delay(betweenLettersPause);
}

void Morse::convertStringToMorseCode(char* word)
{
  Serial.print("convert function");
  delay(1000);
}

void Morse::convertCharToMorseCode(char c)
{
  delay(1000);
}

