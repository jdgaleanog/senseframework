
#include "Arduino.h"
#include "view.h"


void view::outputConfig(int idO, float higherThan, float lowerThan)
{
  led *q = static_cast<led *>(pvOutput[idO]);

  q->configLed(higherThan, lowerThan);
}


void view::outputConfig(int idO, float refer1, int limit1)
{

}
