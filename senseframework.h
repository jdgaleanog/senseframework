#ifndef SENSEFRAMEWORK_H
#define SENSEFRAMEWORK_H
#include "Arduino.h"

#include "src/controller/controller.h"
#include "src/view/view.h"
#include "src/model/model.h"


class sense: public controller, public view

{
  public:
    sense(void);
    int sensorSelect(int type, int pin1);
    int sensorSelect(int type, int pin1, int pin2);
    int outputSelect(int type, int pin1);
    void run();
    float value[2];

};


#endif /* SENSEFRAMEWORK_H */
