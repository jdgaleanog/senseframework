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
        lm35* sensor1;
        sensor1=new lm35();
        pvSensor[idSensor]=sensor1;
        sensor1->initlm35(pin0);

        sensorType[idSensor]=type;
        idSensor=idSensor+1;

        break;

        case LM335:
          initlm335(pin0);
        break;

        case DHT11:
          initDHT(pin0, type);
        break;

        case DHT22:
          initDHT(pin0, type);
        break;
}
}
