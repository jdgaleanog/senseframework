/*
read.cpp - para llamar funciones de lectura de cada sensor
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#include "Arduino.h"



void controller::sensorConfig(int idS, int unit)
{

  switch (sensorType[idS]) {

    case LM35:
    {
      lm35 *q = static_cast<lm35 *>(pvSensor[idS]);

      q->configlm35(unit);
    }
    break;

    case LM335:
    {
      lm335 *q = static_cast<lm335 *>(pvSensor[idS]);

      q->configlm335(unit);
    }
    break;

    case DHT11:
    {
      dht *q = static_cast<dht *>(pvSensor[idS]);
      int variable=unit;
      q->configDHT(variable, 0);
    }
    break;

    case DHT22:
    {
      dht *q = static_cast<dht *>(pvSensor[idS]);
      int variable=unit;
      q->configDHT(variable, 0);
    }
    break;
  }

}

void controller::sensorConfig(int idS,int variable, int unit)

{
  switch (sensorType[idS]) {
    case DHT11:
    {
      dht *q = static_cast<dht *>(pvSensor[idS]);

      q->configDHT(variable, unit);
    }
    break;

    case DHT22:
    {
      dht *q = static_cast<dht *>(pvSensor[idS]);

      q->configDHT(variable, unit);
    }
    break;
  }

}
