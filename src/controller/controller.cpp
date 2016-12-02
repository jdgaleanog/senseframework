#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"

int controller::sensorSelect(int type, int pin0)
{

        sensorInit(type, pin0, 0);
        return idSensor-1;

}

void controller::connectSV(int idS, int idO)
{

  viewsArray[idStruct].idSensor =  idS;
viewsArray[idStruct].idOutput =  idO;
idStruct=idStruct+1;

}

void controller::run()
{
  for (int i = 0; i <idStruct; i++) {

    value[i]=sensorRead(viewsArray[i].idSensor);
    outputShow(viewsArray[i].idOutput, value[i]);

  }

}
