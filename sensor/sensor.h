/*
  sensor.h - Librería
 funcion principal encardad de manjear las demas funciones
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/
#ifndef sensor_h
#define sensor_h
#include "Arduino.h"
#include "sensorlist.h"

#define LM35 1
#define LM335 2
#define DHT11 3
#define DHT22 4
#define TEMPERATURE 5
#define HUMIDITY 6
#define F 7
#define K 8
#define C 9


class sensor : public sensorlist
      {

       public:
         sensor();
         sensor(int type, int pin0); //constructor
         sensor(int type, int pin0, int pin1);
         void init(int type, int pin0, int pin1);
         float read(int variable, int unit);
         float read(int unit);
         int _type;
         int _unit;
         int returnType();
         int returnUnit();


       private:

         int _pin0;
         int _pin1;
         //int _type;
         float _dataReaded;
         int _variable;

};

#endif
