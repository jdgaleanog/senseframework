#ifndef ethernetconfig_h
#define ethernetconfig_h
#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"
#include "ethernetlist.h"
#define MAILALERT 1
#define DATAUPLOAD 2

class ethernetconfig: public ethernetlist
      {

       public:

         ethernetconfig(char server[], byte mac[]); //constructor
         void connect();
         void functions(int function,  char urlMail[], float higherThan, float lowerThan, float var);
         void functions(int function, char url[], String varName[], String value[], int varLength, float minuteInterval);


         char* _server;
         char* _url;
         int _sent;
         int _st;
         byte* _mac;

       private:


};

#endif
