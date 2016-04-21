/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef sensor_h

#define sensor_h

#include "arduino.h"


class sensor
      {

       public:

	sensor(int pin); //constructor

        float lm35();
        float lm335();
        float fahrenheit(float cel);
        float kelvin(float cel);
       private:

      	 int _pin;
      	 float cel;

};




#endif
