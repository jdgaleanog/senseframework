/*
  lm335.h - Librería
para sensar temperatura mediante lm335
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef lm335_h
#define lm335_h
#include "arduino.h"



class lm335
      {

       public:

	//lm335();
	       void initlm335(int pin);
         float readlm335();
         int _pin;
	//int dataReaded;
  	   private:

};

#endif
