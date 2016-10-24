/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef lm35_h
#define lm35_h
#include "arduino.h"


class lm35
      {

       public:
   //lm35();
        void initlm35(int pin);
        float readlm35();
        int _pin;

	     private:

};

#endif
