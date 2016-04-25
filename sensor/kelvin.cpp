#include "arduino.h"

#include "conversion.h"


float conversion::kelvin(float cel)
{
    float kelv=0;
    kelv=cel+273.15;
    return kelv;
}
