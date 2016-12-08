#include "Arduino.h"
#include "view.h"


void view::outputShow(int idO, float var)
{


  switch (outputType[idO]) {

      case LCD:
      {
      Lcd *q = static_cast<Lcd *>(pvOutput[idO]);
      q->setCursor(0,0);
      q->print(q->_name);
      q->setCursor(0,1);
      q->print(var);
    }

        break;

        case LED:
{
        led *q = static_cast<led *>(pvOutput[idO]);
      //q->initlm35(sensorPin1[idS]);

      q->showled(var);
    }
        break;


}



}
