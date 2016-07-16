/*
  lm35.h - Librer�a
 para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef sensorlist_h

#define sensorlist_h


#include "arduino.h"

#include "functionconv.h"


#include "lm35.h"
#include "lm335.h"
#include "dht.h"

class sensorlist : public lm35, public lm335, public dht, public functionconv
      {

       public:

	
};




#endif
