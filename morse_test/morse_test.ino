/*
 * 2021.04.30.
 * REQUIREMENTS: 1 LED
*/

#include <Morse.h>

Morse morse(13, 250);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  morse.convertStringToMorseCode("Hello world");
}
