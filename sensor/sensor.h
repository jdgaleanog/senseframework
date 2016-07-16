/*
  lm35.h - Librería
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/
#ifndef sensor_h
#define sensor_h
#include "arduino.h"
#include "functionconv.h"

#define LM35 1
#define LM335 2
#define DHT11 3
#define DHT22 4
#define TEMPERATURE 5
#define HUMIDITY 6
#define F 7
#define K 8
#define C 9


#include "sensorlist.h"

class sensor : public sensorlist
      {

       public:

	sensor(int type, int pin0); //constructor
	sensor(int type, int pin0, int pin1);
	void init(int type, int pin0, int pin1);
    float read(int variable, int unit);
    float read(int unid);

       private:

    int _pin0;
	int _pin1;
	int _type;
    float _cel;
    int _variable;

};

#endif
