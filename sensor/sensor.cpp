/*

Libejemplo.cpp - Sensado de temperatura con lm35 cpp

Creada por Nombre Autor, Fecha

Lanzado bajo
*/



#include "arduino.h"

#include "sensor.h"


sensor::sensor(int pin)

	{

	 pinMode(pin, INPUT);  //ejemplo
	 	_pin = pin;

    Serial.begin( 9600 );


	}

