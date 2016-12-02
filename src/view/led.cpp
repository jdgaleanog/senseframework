#include "Arduino.h"
#include "led.h"

led::led()
{

}

void led::initled(int pin)
{
  _pin = pin;
  pinMode(pin, OUTPUT);
}

void led::configLed(float higherThan, float lowerThan)
{
  _higherThan=higherThan;
  _lowerThan=lowerThan;

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

void led::showled(float var)
{

  if (_higherThan > _lowerThan) {

    if (var> _higherThan) {
      digitalWrite(_pin,HIGH);
    }
    else if (var < _lowerThan) {
      digitalWrite(_pin,HIGH);
    }
    else {
      digitalWrite(_pin, LOW);
    }
  }

  if (_higherThan < _lowerThan) {

    if ((var > _higherThan)&&(var < _lowerThan)){
      digitalWrite(_pin,HIGH);
    }
    else {
      digitalWrite(_pin, LOW);
    }
  }
}
