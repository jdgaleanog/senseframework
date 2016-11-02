#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "arduino.h"


#define LM35 1
#define LM335 2
#define DHT11 3
#define DHT22 4
#define TEMPERATURE 5
#define HUMIDITY 6
#define F 7
#define K 8
#define C 9

typedef struct{
  int typeSensor;
  int typeView;
}view_t;


class controller
{
  public:


    int sensor(int type, int pin);
//    void show(int id, int type, int pin);
  //  void run(void);

  private:
    view_t viewsArray[10];

    int sensorType[10];
    int sensorPin1[10];

};


#endif /* CONTROLLER_H */
