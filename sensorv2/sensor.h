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

#define LM35 1
#define LM335 2

#include "sensorlist.h"

class sensor : public sensorlist
      {

       public:

	sensor(int type, int pin0); //constructor

	sensor(int type, int pin0, int pin1);
	void init(int type, int pin0, int pin1);
        float read(); 

       private:

      	int _pin0;
	int _pin1;
	int _type;
      	 float _cel;

};




#endif
