#ifndef SENSEFRAMEWORK_H
#define SENSEFRAMEWORK_H

#include "src/controller/controller.h"
#include "arduino.h"
#include "src/view/view.h"
#include "src/model/model.h"

class sense: public controller
{
  public:
    sense(void);
    int sensorSelect(int type, int pin);

};


#endif /* SENSEFRAMEWORK_H */
