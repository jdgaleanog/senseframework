#include "arduino.h"

#include "sensor.h"


float sensor::kelvin(float cel)
{
    float kelv=0;
    kelv=cel+273.15;
    return kelv;
}
