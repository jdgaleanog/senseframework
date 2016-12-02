#include "Arduino.h"
#include "view.h"


void view::outputShow(int idV, float var)
{


  switch (outputType[idV]) {
    case LCD:


        break;

        case LED:
{
        led *q = static_cast<led *>(pvOutput[idV]);
      //q->initlm35(sensorPin1[idS]);

      q->showled(var);
    }
        break;


}



}
