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
  int betweenLetterPartsPause;
  int betweenLettersPause;
  int betweenWordsPause;
  public:
    Morse(int pinNumber, int timeUnit);
    void dot();
    void dash();
    void convertStringToMorseCode(char* word);
    void convertCharToMorseCode(const char c);
    bool validateChar(const char c);
};

#endif
