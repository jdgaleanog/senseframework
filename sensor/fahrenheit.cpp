#include "arduino.h"

#include "functionconv.h"


float functionconv::fahrenheit(float cel)
{
    float fahr=0;
    fahr=(cel*9)/5 + 32;
    return fahr;
}
