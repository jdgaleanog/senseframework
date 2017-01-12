
#include "Arduino.h"
#include "view.h"


void view::outputConfig(int idO, float higherThan, float lowerThan)
{
  switch (outputType[idO]) {

    case LED:
    {
      led *q = static_cast<led *>(pvOutput[idO]);

      q->configLed(higherThan, lowerThan);
    }
    break;


    case MAILALERT:
    {
      alertByEmail *q = static_cast<alertByEmail *>(pvOutput[idO]);

      q->configMail(higherThan, lowerThan);
    }
    break;

  }
}



void view::outputConfig(int idO, float refer1, int limit1)
{
  led *q = static_cast<led *>(pvOutput[idO]);

  q->configLed(refer1, limit1);
}

void view::outputConfig(int idO, char const* name)
{
  Lcd *q = static_cast<Lcd *>(pvOutput[idO]);

  q->configLcd(name);
}
