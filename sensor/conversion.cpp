/*

conversion.cpp - llamar funciones de temperatura

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "arduino.h"
#include "functionconv.h"


float functionconv::conversion(float dataReaded, int unit)

	{

     _dataReaded=dataReaded;


     switch(unit)       {

			 	case F:

					_dataReaded=fahrenheit(_dataReaded);

        break;


				case K:

					_dataReaded=kelvin(_dataReaded);

        break;
     }

		 return _dataReaded;

	}
