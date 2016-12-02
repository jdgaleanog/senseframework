#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Arduino.h"

#include "../model/model.h"

#define LM35 1
#define LM335 2
#define DHT11 11
#define DHT22 22
#define TEMPERATURE 5
#define HUMIDITY 6
#define F 7
#define K 8
#define C 9

typedef struct{
  int idSensor;
  int idOutput;
}view_t;


class controller: public model
{
  public:


    int sensorS(int type, int pin0);



    void sensorInit(int type, int pin0, int pin1);
    void connectSV(int idS, int idO);
    float sensorRead(int idS);
    void sensorConfig(int idS, int unit);
    void sensorConfig(int idS,int variable, int unit);


//    void show(int id, int type, int pin);
  //  void run(void);

  view_t viewsArray[10];

  int sensorType[10];
  int sensorPin1[10];
  int sensorPin2[10];
  int idSensor=0;


  int prueba=30;
  float _dataReaded;
  void * pvSensor[10];
    int enter=0;
    int idStruct=0;


  private:


};


#endif /* CONTROLLER_H */
