/*
  read.cpp - para llamar funciones de lectura de cada sensor
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#include "Arduino.h"
#include "sensor.h"


float sensor::read(int unit)
  {
    _unit=unit;
    switch (_type) {

        case LM35:
            _dataReaded=readlm35();
        break;

        case LM335:
            _dataReaded=readlm335();
        break;

        case DHT11:
            _variable=unit;
            if (_variable=HUMIDITY)
          {
            _dataReaded=readHumidity();
          }
        break;

        case DHT22:
        _variable=unit;
        if (_variable=HUMIDITY)
      {
        _dataReaded=readHumidity();
      }
        break;
    }

    if (unit=C){
      }

    else
      {
        _dataReaded=conversion(_dataReaded, unit);
      }

        return _dataReaded;
  }


float sensor::read(int variable, int unit)

  {
    _variable=variable;
    _unit=unit;

    switch (_type) {

        case DHT11:
            _dataReaded=readTemperature(false);
        break;

        case DHT22:
            _dataReaded=readTemperature(false);
        break;
    }

   if (unit==C)
    {
        _dataReaded=_dataReaded;
    }

    if((unit==F)||(unit==K))
    {
        _dataReaded=conversion(_dataReaded, unit);
    }

    return _dataReaded;
}
