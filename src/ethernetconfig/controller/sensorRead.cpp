#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"

float controller::sensorRead(int idS)
{


  switch (sensorType[idS]) {
    case LM35:
    {
          //initlm35(sensorPin1[idS]);
          //_dataReaded=readlm35();
          lm35 *q = static_cast<lm35 *>(pvSensor[idS]);
 //q->initlm35(sensorPin1[idS]);
  _dataReaded=q->readlm35();
}
        break;

       case LM335:
       {
        lm335 *q = static_cast<lm335 *>(pvSensor[idS]);
//q->initlm35(sensorPin1[idS]);
  _dataReaded=q->readlm335();
       }
       break;

       case DHT11:
       {
        dht *q = static_cast<dht *>(pvSensor[idS]);
//q->initlm35(sensorPin1[idS]);
  _dataReaded=q->readDHT();

       }
       break;

       case DHT22:
       {
        dht *q = static_cast<dht *>(pvSensor[idS]);
//q->initlm35(sensorPin1[idS]);
  _dataReaded=q->readDHT();

       }
       break;

}

return _dataReaded;

}
