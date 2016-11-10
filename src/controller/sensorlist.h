/*
  sensorlist.h - Libreria
 lista de librerias a heredar
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef sensorlist_h
#define sensorlist_h

#include "Arduino.h"
#include "../sensor/functionconv.h"
#include "../sensor/lm35.h"
#include "../sensor/lm335.h"
#include "../sensor/dht.h"

class sensorlist : public lm35, public lm335, public dht, public functionconv
{

       public:

};


#endif
