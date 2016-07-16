/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef conversion_h

#define conversion_h

#include "arduino.h"

#define F 7

#define K 8

class functionconv
      {

       public:

    functionconv();

	float conversion(float cel, int unit); //constructor

        float fahrenheit(float cel);
        float kelvin(float cel);
       private:

      	 float _cel;

};




#endif
