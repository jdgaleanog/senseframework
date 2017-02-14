#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Arduino.h"
#include "../model/model.h"
#include "../view/view.h"
#include "Ethernet.h"
#include "SPI.h"

#define LM35 1
#define LM335 2
#define DHT11 11
#define DHT22 22
#define TEMPERATURE 5
#define HUMIDITY 6
#define F 7
#define K 8
#define C 9
#define MAILALERT 10
#define DATAUPLOAD 12

typedef struct{
  int idSensor;
  int idOutput;
  String name;
}view_t;


class controller: public model, public view
{
public:


  int sensorSelect(int type, int pin0);
  void sensorInit(int type, int pin0, int pin1);
  void sensorConfig(int idS, int unit);
  void sensorConfig(int idS,int variable, int unit);
  float sensorRead(int idS);
  void sensorName(int idS, char Sname[]);
  String sensorName(int idS);
  void connectSV(int idS, int idO);
  void connectSV(int idS, int idO, String name);
  void ethernetConfig( byte mac[]);
  void run();
  float sensorValue[10];

private:

  view_t viewsArray[10];
  int sensorType[10];
  int idSensor=0;
  float _dataReaded=NULL;
  void * pvSensor[10];
  int idStruct=0;
  unsigned long currentMillis;
  int _sent;
  int j=0;
  String value[10];
  String varName[10];
  String name[10];


};


#endif /* CONTROLLER_H */
