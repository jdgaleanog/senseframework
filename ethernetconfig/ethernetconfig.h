#ifndef ethernetconfig_h
#define ethernetconfig_h
#include "arduino.h"


class ethernetconfig
      {

       public:

         ethernetconfig(String url [], String varName[], String value[]); //constructor
         int retornar();


       private:

         int _save;
         String _url [];

};

#endif
