#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"

void controller::outputShow(int idV)
{


  switch (outputType[idV]) {
    case LM35:
          initlm35(sensorPin1[idV]);
          _dataReaded=readlm35();

        break;

        case LM335:
          initlm335(sensorPin1[idV]);
        break;


}



}
