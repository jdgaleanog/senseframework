#include "Arduino.h"
#include "senseframework.h"


sense::sense(void)
{


}

int sense::sensorSelect(int type, int pin1)
{
  int id;
  id=sensorS(type,pin1);

  return id;
}

int sense::sensorSelect(int type, int pin1, int pin2)
{
  int id;
  //id=sensorS(type,pin1,pin2);
  id=prueba;
  return id;
}

int sense::outputSelect(int type, int pin1)
{

  outputS(type,  pin1);

}

void sense::run()
{
  for (int i = 0; i <idStruct; i++) {

    value[i]=sensorRead(viewsArray[i].idSensor);
    outputShow(viewsArray[i].idOutput, value[i]);

  }

}
// Funciones de cofiguración del framework
