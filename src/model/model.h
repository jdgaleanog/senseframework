/*
sensorlist.h - Libreria
lista de librerias a heredar
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef model_h
#define model_h

#include "Arduino.h"
#include "lm35.h"
#include "lm335.h"
#include "dht.h"



class model : public lm35, public lm335, public dht
{

public:

};


#endif
