#include "arduino.h"
#include "led.h"


void led::initled(int pin)
{
   _pin = pin;
   pinMode(pin, OUTPUT);
}


void led::showled(float refer1, int limit1, float var)
{


    switch (limit1) {

        case HIGHER:

            if (var > refer1)
            {
            digitalWrite(_pin,HIGH);
            }
            if (var < refer1)
            {
            digitalWrite(_pin,LOW);
            }

        break;

        case LOWER:

            if (var < refer1)
            {
            digitalWrite(_pin,HIGH);
            }
            if (var > refer1)
            {
            digitalWrite(_pin,LOW);
            }

        break;

}
}

void led::showled(float higherThan, float lowerThan, float var)
{


        if (higherThan > lowerThan) {

        if (var> higherThan) {
            digitalWrite(_pin,HIGH);
            }
        else if (var < lowerThan) {
            digitalWrite(_pin,HIGH);
            }
        else {
            digitalWrite(_pin, LOW);
            }
          }

        if (higherThan < lowerThan) {

        if ((var > higherThan)&&(var < lowerThan)){
            digitalWrite(_pin,HIGH);
            }
        else {
            digitalWrite(_pin, LOW);
            }
        }

}
