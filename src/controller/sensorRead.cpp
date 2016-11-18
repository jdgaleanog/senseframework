#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"

float controller::sensorRead(int idS)
{


  switch (sensorType[idS]) {
    case LM35:
          //initlm35(sensorPin1[idS]);
          //_dataReaded=readlm35();
          lm35 *q = static_cast<lm35 *>(pvSensor[0]);
 q->initlm35(sensorPin1[idS]);
  _dataReaded=q->readlm35();

        break;

       case LM335:
       initlm335(sensorPin1[idS]);
       break;


}

return _dataReaded;

}
