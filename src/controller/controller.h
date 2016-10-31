#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller.h"
#include "../view/view.h"
#include "../model/model.h"

typedef struct{
  int typeSensor;
  int tyṕeView;
}view_t;

class controller
{
  public:
    sense(void);

    int sensor(int type, int pin);
    void show(int id, int type, int pin);
    void run(void);

  private:
    view_t viewsArray[10];
};


#endif /* CONTROLLER_H */
