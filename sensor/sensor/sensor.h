/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef sensor_h

#define sensor_h

#include "arduino.h"

#include "conversion.h"


class sensor: public conversion
      {

       public:

	sensor(int pin); //constructor

        float lm35();
        float lm335();
        
       private:

      	 int _pin;
      	 float cel;

};




#endif
