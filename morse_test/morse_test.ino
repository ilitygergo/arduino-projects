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
