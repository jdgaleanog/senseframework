/*

Libejemplo.cpp - Sensado de temperatura con lm35 cpp

Creada por Nombre Autor, Fecha

Lanzado bajo
*/



#include "arduino.h"

#include "sensor.h"




sensor::sensor(int type, int pin0)
	{

_type=type;
_pin0=pin0;

init(_type, _pin0, 0);

	}



sensor::sensor(int type, int pin0, int pin1)
	{
_type=type;
_pin0=pin0;
_pin1=pin1;
init(_type, _pin0, _pin1);

	}