#ifndef dbUpload_h
#define dbUpload_h
#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"

class dbUpload

 {

 public:

   dbUpload();
   void dataUpload (char server[], char url[], String varName[], String value[], int varLength, float minuteInterval);

private:

int _sent;

};
#endif
