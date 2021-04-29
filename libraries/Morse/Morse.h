/*
 * Created by igergg
 * 2021-04-28
*/

#ifndef Morse_h
#define Morse_h

class Morse
{
  int pinNumber;
  int dotSpan;
  int dashSpan;
  int betweenSameLettersPause;
  int betweenLettersPause;
  int betweenWordsPause;
  public:
    Morse(int pinNumber, int timeUnit);
    void dot();
    void dash();
    void convertStringToMorseCode(char* word);
    void convertCharToMorseCode(char c);
};

#endif
