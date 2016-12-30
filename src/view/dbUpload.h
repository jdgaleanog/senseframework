#ifndef dbUpload_h
#define dbUpload_h
#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"

class dbUpload

 {

 public:

   dbUpload();
   void initdbUpload(char server[], char url[],  float minuteInterval);
   void dataUpload (String varName[], String value[], int varLength);

private:

int _sent;

char const* serverdb;
char const* urldb;
float _minuteInterval;

};
#endif
