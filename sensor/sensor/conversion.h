/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef conversion_h

#define conversion_h

#include "arduino.h"


class conversion 
      {

       public:

	conversion(); //constructor

        float fahrenheit(float cel);
        float kelvin(float cel);
       private:

      	 float cel;

};




#endif
