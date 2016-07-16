#include "arduino.h"
#include "sensor.h"



float sensor::read(int unit)
{
    switch (_type) {

        case LM35:

        _cel=readlm35();

        break;


        case LM335:
            _cel=readlm335();
        break;

        case DHT11:

            _cel=readHumidity();

        break;

        case DHT22:

            _cel=readHumidity();

        break;

    }

if (unit=C)
{

}
else
{
    _cel=conversion(_cel, unit);

}

    return _cel;
}


float sensor::read(int variable, int unit)

{

    _variable=variable;

    switch (_type) {

        case DHT11:
            _cel=readTemperature(false);
        break;

        case DHT22:
            _cel=readTemperature(false);
        break;
    }

   if (unit==C)
    {
        _cel=_cel;
    }

    if((unit==F)||(unit==K))
    {
    _cel=conversion(_cel, unit);
    }

    return _cel;
}
