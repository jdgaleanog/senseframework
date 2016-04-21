#include "arduino.h"

#include "sensor.h"


float sensor::fahrenheit(float cel)
{
    float fahr=0;
    fahr=(cel*9)/5 + 32;
    return fahr;
}
