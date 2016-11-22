#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Arduino.h"
#include "../view/view.h"
#include "../model/model.h"

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
  int idSensor;
  int idOutput;
}view_t;


class controller: public model, public view
{
  public:


    int sensorS(int type, int pin0);

    int outputS(int idS, int type, int pin1);
    int outputS(int type, int pin);
    int outputS(int type, uint8_t rs, uint8_t enable,
           uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
           uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    int outputS(int type, uint8_t rs, uint8_t rw, uint8_t enable,
           uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
           uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    int outputS(int type, uint8_t rs, uint8_t rw, uint8_t enable,
           uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    int outputS(int type, uint8_t rs, uint8_t enable,
           uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

    void sensorInit(int type, int pin0, int pin1);
    void connectSV(int idS, int idO);
    float sensorRead(int idS);
    void outputShow(int idV);

//    void show(int id, int type, int pin);
  //  void run(void);

  view_t viewsArray[10];

  int sensorType[10];
  int sensorPin1[10];
  int sensorPin2[10];
  int idSensor=0;

  int outputType[10];
  int outputPin1[10];
  int idOutput=0;
  int idStruct=0;

  int prueba=30;
  float _dataReaded;
  void * pvSensor[10];
  void * pvOutput[10];

  private:


};


#endif /* CONTROLLER_H */
