/*
Eliminar
*/

#ifndef conversion_h
#define conversion_h
#include "arduino.h"

#define F 7

#define K 8

class functionconv
      {

       public:

        functionconv();
        float conversion(float dataReaded, int unit); //constructor
        float fahrenheit(float dataReaded);
        float kelvin(float dataReaded);

       private:

      	 float _dataReaded;

};




#endif
