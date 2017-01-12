/*
lm335.h - Librería
para sensar temperatura mediante lm335
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef lm335_h
#define lm335_h
#include "Arduino.h"
#include "functionconv.h"
#define F 7
#define K 8
#define C 9


class lm335: public functionconv
{

public:

  lm335();
  void initlm335(int pin);
  void configlm335(int unit);
  float readlm335();
  int _pin;
  int _unit;

private:

};

#endif
