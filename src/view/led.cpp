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
  _conLed=0;

}

void led::configLed(float refer1, int limit1)
{
  _refer1=refer1;
  _limit1=limit1;
  _conLed=1;
}

void led::showled(float var)
{

  if (_conLed==1)
  {
    switch (_limit1) {

      case HIGHER:

      if (var > _refer1)
      {
        digitalWrite(_pin,HIGH);
      }
      if (var < _refer1)
      {
        digitalWrite(_pin,LOW);
      }

      break;

      case LOWER:

      if (var < _refer1)
      {
        digitalWrite(_pin,HIGH);
      }
      if (var > _refer1)
      {
        digitalWrite(_pin,LOW);
      }

      break;

    }
  }

  if(_conLed==0)
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
}
