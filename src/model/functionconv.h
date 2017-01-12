/*
functionconv.h - Libreria
para convertir temperatura leida
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef functionconv_h
#define functionconv_h
#include "Arduino.h"

#define F 7
#define K 8

class functionconv
{

public:

  float conversion(float dataReaded, int unit);
  float fahrenheit(float dataReaded);
  float kelvin(float dataReaded);

private:

  float _dataReaded;

};

#endif
