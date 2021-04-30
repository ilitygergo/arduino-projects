#include "Arduino.h"
#include "Morse.h"

char CharacterBinaryCode[36][6] = {
	{'a','.','-'},
	{'b','-','.','.','.'},
	{'c','-','.','-','.'},
	{'d','-','.','.'},
	{'e','.'},
	{'f','.','.','-','.'},
	{'g','-','-','.'},
	{'h','.','.','.','.'},
	{'i','.','.'},
	{'j','.','-','-','-'},
	{'k','-','.','-'},
	{'l','.','-','.','.'},
	{'m','-','-'},
	{'n','-','.'},
	{'o','-','-','-'},
	{'p','-','-','-','.'},
	{'q','-','-','.','-'},
	{'r','.','-','.'},
	{'s','.','.','.'},
	{'t','-'},
	{'u','.','.','-'},
	{'v','.','.','.','-'},
	{'w','.','-','-'},
	{'x','-','.','.','-'},
	{'y','-','.','-','-'},
	{'z','-','-','.','-'},
	{'1','.','-','-','-','-'},
	{'2','.','.','-','-','-'},
	{'3','.','.','.','-','-'},
	{'4','.','.','.','.','-'},
	{'5','.','.','.','.','.'},
	{'6','-','.','.','.','.'},
	{'7','-','-','.','.','.'},
	{'8','-','-','-','.','.'},
	{'9','-','-','-','-','.'},
	{'0','-','-','-','-','-'},
};

Morse::Morse(int pin, int timeUnit) {
  pinMode(pin, OUTPUT);
  pinNumber = pin;
  dotSpan = timeUnit;
  dashSpan = timeUnit * 3;
  betweenLetterPartsPause = timeUnit;
  betweenLettersPause = timeUnit * 3;
  betweenWordsPause = timeUnit * 7;
}

void Morse::dot() {
  digitalWrite(pinNumber, HIGH);
  delay(dotSpan);
  digitalWrite(pinNumber, LOW);
}

void Morse::dash() {
  digitalWrite(pinNumber, HIGH);
  delay(dashSpan);
  digitalWrite(pinNumber, LOW);
}

void Morse::convertStringToMorseCode(char* word) {
  for (char c = *word; c; c=*++word) {
    convertCharToMorseCode(tolower(c));
	if (c == ' ') Serial.print(" / ");
  }

  Serial.print("\n");
  delay(betweenWordsPause);
}

void Morse::convertCharToMorseCode(const char c) {
  if (!validateChar(c)) return;

  Serial.print(c);
  Serial.print(": ");

  for (int i = 0; i < (sizeof(CharacterBinaryCode) / sizeof(CharacterBinaryCode[0])); i++) {
    if (CharacterBinaryCode[i][0] != c) continue;

	for (int j = 1; j < sizeof(CharacterBinaryCode[0]); j++)
	{
      if (!CharacterBinaryCode[i][j]) {
		break;
	  }

	  if (CharacterBinaryCode[i][j] == '.') {
		Serial.print(".");
		dot();
	  }

	  if (CharacterBinaryCode[i][j] == '-') {
		Serial.print("-");
		dash();
	  }

	  delay(betweenLetterPartsPause);
	}

    Serial.print(" ");
	delay(betweenLettersPause);
	break;
  }
}

bool Morse::validateChar(const char c) {
  if (!(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9')) return false;

  return true;
}
