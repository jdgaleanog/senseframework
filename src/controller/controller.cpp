#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"

int controller::sensorC(int type, int pin1)
{
  lm35* sensor1;
  sensor1=new lm35();
  pvSensor[0]=sensor1;
  sensor1->initlm35(pin1);

  sensorType[idSensor]=type;
  sensorPin1[idSensor]=pin1;
  //sensorPin2[idSensor]=pin2;
  idSensor=idSensor+1;
  return idSensor-1;

}

int controller::sensorC(int type, int pin1, int pin2)
{


  sensorType[idSensor]=type;
  sensorPin1[idSensor]=pin1;
  sensorPin2[idSensor]=pin2;
  idSensor=idSensor+1;
  return idSensor-1;

}
int controller::outputC(int idS, int output, int pin1)
{
    outputType[idV]=output;
    outputPin1[idV]=pin1;

    viewsArray[idV].idSensor =  idS;
    viewsArray[idV].idOutput =  idV;
    idV=idV+1;
    return idV-1;



}
