#ifndef led_h

#define led_h
#include "arduino.h"
#define HIGHER 1
#define LOWER 2
class led
      {

       public:

            led();
            void initled(int pin);
            void showled(float refer1, int limit1, float var);
            void showled(float refer1, float refer2, float var);


       private:

            int _pin;

       };
#endif
