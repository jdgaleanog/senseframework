#include "Arduino.h"
#include "view.h"


void controller::outputShow(int idV)
{


  switch (outputType[idV]) {
    case LM35:


        break;

        case LM335:
          initlm335(sensorPin1[idV]);
        break;


}



}
