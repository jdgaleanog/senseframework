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

      q->showled((float)10.0, (float)20.0, var);
    }
        break;


}



}
