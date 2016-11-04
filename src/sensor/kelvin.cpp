/*
kelvin.cpp - pasar de Celsius a kelvin

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "Arduino.h"
#include "functionconv.h"


float functionconv::kelvin(float dataReaded)
{
    float kelv=0;
    kelv=dataReaded+273.15;
    return kelv;
}
