/*

Libejemplo.cpp - Sensado de temperatura con lm35 cpp

Creada por Nombre Autor, Fecha

Lanzado bajo
*/



#include "arduino.h"

#include "functionconv.h"


float functionconv::conversion(float cel, int unit)

	{

     _cel=cel;


     switch(unit)       {

        case F:

        _cel=fahrenheit(_cel);

        break;


        case K:

        _cel=kelvin(_cel);

        break;
     }

return _cel;

	}

