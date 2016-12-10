/*
init.cpp - inicializar sensores

Creada por Nombre Autor, Fecha

Lanzado bajo
*/

#include "Arduino.h"
#include "controller.h"
//#include "lm35.h"
void controller::sensorInit(int type, int pin0, int pin1)
{

    switch (type) {

        case LM35:
        {
        lm35* sensorlm35;
        sensorlm35=new lm35();
        pvSensor[idSensor]=sensorlm35;
        sensorlm35->initlm35(pin0);

        sensorType[idSensor]=type;
        idSensor=idSensor+1;

      }
        break;

        case LM335:
        {
        lm335* sensorlm335;
        sensorlm335=new lm335();
        pvSensor[idSensor]=sensorlm335;
        sensorlm335->initlm335(pin0);

        sensorType[idSensor]=type;
        idSensor=idSensor+1;

      }
        break;

        case DHT11:
        {
        dht* sensordht11;
        sensordht11=new dht();
        pvSensor[idSensor]=sensordht11;
        sensordht11->initDHT(pin0, type);
        sensordht11->begin();

        sensorType[idSensor]=type;
        idSensor=idSensor+1;
        
      }
        break;

        case DHT22:
        {
        dht* sensordht22;
        sensordht22=new dht();
        pvSensor[idSensor]=sensordht22;
        sensordht22->initDHT(pin0, type);
        sensordht22->begin();

        sensorType[idSensor]=type;
        idSensor=idSensor+1;

      }
        break;
    }
}
