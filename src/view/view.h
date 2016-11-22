/*
  view.h - Librería
 mostrar resultados de sensado
Creada por Nombre Autor, Fecha

Lanzado bajo licencia ---
*/

#ifndef view_h

#define view_h
#include "Arduino.h"
#include "viewlist.h"
#include "../controller/controller.h"
#define LCD 1
#define LED 2




class view: public viewlist

      {

       public:


       void initview(int type, int pin0);

       void initview(uint8_t rs, uint8_t rw, uint8_t enable,
       			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
       			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

       void initview(uint8_t rs, uint8_t enable,
      			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
      			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

       void initview(uint8_t rs, uint8_t rw, uint8_t enable,
            		     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

       void initview(uint8_t rs,  uint8_t enable,
            		     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);


       void show(float refer1, float refer2, float var);
       void show(float refer1, int limit1, float var);
       void show(char const* name, float var);
       void show(char const* name, float var, char const* name2, float var2);

       private:

       const float cont=0;
       int _pin;
       int _type;
       int _rs;
       int _rw;
       int _enable;
       int _d0;
       int _d1;
       int _d2;
       int _d3;
       int _d4;
       int _d5;
       int _d6;
       int _d7;
       int _name;
       float _var;
       int _name2;
       float _var2;



};
#endif
