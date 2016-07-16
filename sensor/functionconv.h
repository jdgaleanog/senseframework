/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef functionconv_h

#define functionconv_h

#include "arduino.h"

#define F 7

#define K 8

class functionconv
      {

       public:

  

	float conversion(float cel, int unit); //constructor

        float fahrenheit(float cel);
        float kelvin(float cel);
       private:

      	 float _cel;

};




#endif
