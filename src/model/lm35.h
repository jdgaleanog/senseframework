/*
lm35.h - Librería
para sensar temperatura mediante lm35
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef lm35_h
#define lm35_h
#include "Arduino.h"
#include "functionconv.h"
#define F 7
#define K 8
#define C 9


class lm35: public functionconv
{
  
public:
  lm35();
  void initlm35(int pin);
  void configlm35(int unit);
  float readlm35();
  int _pin;
  int _unit;

private:

};

#endif
