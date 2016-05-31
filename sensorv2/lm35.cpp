﻿/*

Libejemplo.cpp - Sensado de temperatura con lm35 cpp

Creada por Nombre Autor, Fecha

Lanzado bajo 
*/



#include "arduino.h"

#include "lm35.h"



lm35::lm35()

	{
 


	}


void lm35::initlm35(int pin)

	{
 
	 pinMode(pin, INPUT);  //ejemplo
  
	_pin = pin;

}


float lm35::readlm35()

{


int val = analogRead(_pin);
float mv = (val/1024.0)*5000; 
float cel = mv/10;
return cel;
}