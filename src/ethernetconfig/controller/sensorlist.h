/*
  sensorlist.h - Libreria
 lista de librerias a heredar
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef sensorlist_h
#define sensorlist_h

#include "Arduino.h"
#include "../model/functionconv.h"
#include "../model/lm35.h"
#include "../model/lm335.h"
#include "../model/dht.h"

class sensorlist : public lm35, public lm335, public dht, public functionconv
{

       public:

};


#endif
