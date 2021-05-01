#include <Morse.h>

#define ledPin 13 // LED pin number
#define signalLength 250 // Signal length in milliseconds

Morse morse(ledPin, signalLength);

void setup()
{
  Serial.begin(9600); // for monitoring
}

void loop()
{
  morse.convertStringToMorseCode("Hello world");
}
