﻿/*
Lm35.cpp - Sensado de temperatura con lm35

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "Arduino.h"
#include "lm35.h"
lm35::lm35()
	{
	}


void lm35::initlm35(int pin)

	{

	 	pinMode(pin, INPUT);  //ejemplo

		_pin = pin;

	}

	void lm35::configlm35(int unit)

		{
			_unit = unit;
		}

float lm35::readlm35()

	{


		int val = analogRead(_pin);
		float mv = (val/1024.0)*5000;
		float dataReaded = mv/10;


		if (_unit==C){

			}

		else
			{
				dataReaded=conversion(dataReaded, _unit);

			}

				return dataReaded;
	}