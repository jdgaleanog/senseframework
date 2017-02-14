/*
lm335.cpp - Sensado de temperatura con lm335

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "Arduino.h"
#include "lm335.h"

lm335::lm335()
{
}

void lm335::initlm335(int pin)

{

	_pin = pin;

}

void lm335::configlm335(int unit)

{
	_unit = unit;
}

float lm335::readlm335()
{
	int degC = 0;
	int degC1 = 0;
	int degC2 = 0;
	int degC3 = 0;
	float dataReaded = 0;

	degC = analogRead(_pin);
	degC1 = analogRead(_pin);
  degC2 = analogRead(_pin);
	degC3 = analogRead(_pin);
	degC=(degC1+degC2+degC3)/3;
	dataReaded = (degC*5 / 1024.0 *1000/10)-273.15;

	if (_unit==C){

	}

	else
	{
		dataReaded=conversion(dataReaded, _unit);

	}

	return dataReaded;

}
