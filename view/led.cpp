#include "arduino.h"
#include "led.h"

led::led()
{

}

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

void led::showled(float refer1, float refer2, float var)
{


        if (refer1 > refer2) {

            if (var> refer1)
            {
            digitalWrite(_pin,HIGH);
            }
            else if (var < refer2)
            {
            digitalWrite(_pin,HIGH);
            }
            else
            {
            digitalWrite(_pin, LOW);
            }
        }

                if (refer1 < refer2) {

            if ((var > refer1)&&(var < refer2))
            {
            digitalWrite(_pin,HIGH);
            }
            else
            {
            digitalWrite(_pin, LOW);
            }
        }


}



