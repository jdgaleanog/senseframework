#include "arduino.h"

#include "functionconv.h"


float functionconv::kelvin(float cel)
{
    float kelv=0;
    kelv=cel+273.15;
    return kelv;
}
