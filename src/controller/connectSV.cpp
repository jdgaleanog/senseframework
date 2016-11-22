#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"


void controller::connectSV(int idS, int idO)
{

    viewsArray[idStruct].idSensor =  idS;
    viewsArray[idStruct].idOutput =  idO;
    idStruct=idStruct+1;


}
