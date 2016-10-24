/*
fahrenheit.cpp - pasar de celcius a fahrenheit

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "arduino.h"
#include "functionconv.h"


float functionconv::fahrenheit(float dataReaded)
{
    float fahr=0;
    fahr=(dataReaded*9)/5 + 32;
    return fahr;
}
