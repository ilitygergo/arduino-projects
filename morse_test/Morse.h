/*
 * Created by igergg
 * 2021-04-28
*/

#ifndef Morse_h
#define Morse_h

class Morse
{
  int pin;
  int interval;
  public:
    Morse(int pin, int interval);
    void dot();
    void dash();
    void convertStringToMorseCode(char* word);
    void convertCharToMorseCode();
    void convertBinaryToMorseCode();
};

#endif
