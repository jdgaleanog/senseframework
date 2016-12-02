#ifndef led_h

#define led_h
#include "Arduino.h"
#define HIGHER 1
#define LOWER 2
class led
      {

       public:
            led();
            void initled(int pin);
            void configLed(float higherThan, float lowerThan);
            void showled(float refer1, int limit1, float var);
            void showled(float var);


       private:

            int _pin;
            float _higherThan;
            float _lowerThan;

       };
#endif
