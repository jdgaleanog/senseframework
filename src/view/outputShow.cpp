#include "Arduino.h"
#include "view.h"


void view::outputShow(int idO, float var)
{

  //currentMillisView=millis();
  switch (outputType[idO]) {

    case LCD:
    {
      if ((currentMillisView - previousMillis >= _interval)&&(next==actual))
      {

        previousMillis = currentMillisView;
        Lcd *q = static_cast<Lcd *>(pvOutput[idO]);
        //q->begin(16,2);
        if (lcdnum>1)
        {
          q->clear();
        }

        q->setCursor(0,0);
        q->print(q->_name);
        q->setCursor(0,1);
        q->print(var);
        next=next+1;
        if (next==(lcdnum))
        {
          next=0;
        }
      }

      actual=actual+1;

      if (actual==(lcdnum))
      {
        actual=0;
      }
    }


    break;

    case LED:
    {
      led *q = static_cast<led *>(pvOutput[idO]);
      //q->initlm35(sensorPin1[idS]);

      q->showled(var);
    }
    break;

    case MAIL:
    {
      alertByEmail *q = static_cast<alertByEmail *>(pvOutput[idO]);
      //q->initlm35(sensorPin1[idS]);

      q->mailAlert(var);
    }
    break;

  }

}

void view::outputShow(String varName[], String value[], int length, int idO)
{
     dbUpload *q = static_cast<dbUpload *>(pvOutput[idO]);
       q->dataUpload (varName, value, length);
}
