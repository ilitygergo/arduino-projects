#include <Morse.h>

Morse morse(13, 250);

void setup()
{
}

void loop()
{
  morse.convertBinaryToMorseCode();
  delay(3000);
}
