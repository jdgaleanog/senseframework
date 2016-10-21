/*
lm335.cpp - Sensado de temperatura con lm335

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "arduino.h"
#include "lm335.h"

//lm335::lm335()
	//{
	//}

void lm335::initlm335(int pin)

	{

	 	pinMode(pin, INPUT);  //ejemplo

		_pin = pin;

	}


float lm335::readlm335()
	{
		int degC = 0;              // fija los tipos de variables
		float dataReaded = 0;

 		degC = analogRead(_pin);                                     // lee el pin analogico 0
 		dataReaded = (degC*5 / 1024.0 *1000/10)-273.15;     // pasa el valor de voltaje de 5V a formato
		return dataReaded;

	}
