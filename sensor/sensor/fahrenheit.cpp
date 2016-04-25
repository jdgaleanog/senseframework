#include "arduino.h"

#include "conversion.h"


float conversion::fahrenheit(float cel)
{
    float fahr=0;
    fahr=(cel*9)/5 + 32;
    return fahr;
}
