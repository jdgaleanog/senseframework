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

#define LCD 1
#define LED 2
#define WEB 3
#define MAIL 4





class view: public viewlist

      {

       public:

         int outputSelect(int type, int pin);
         int outputSelect(int type,  char serverMail[], char urlMail[]);
         int outputSelect(int type, char server[], char url[],  float minuteInterval);
         int outputSelect(int type, uint8_t rs, uint8_t enable,
                uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
         int outputSelect(int type, uint8_t rs, uint8_t rw, uint8_t enable,
                uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
         int outputSelect(int type, uint8_t rs, uint8_t rw, uint8_t enable,
                uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
         int outputSelect(int type, uint8_t rs, uint8_t enable,
                uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);


       void initview(int type);
       void initview(int type, int pin0);

       void initview(int type,  float minuteInterval);

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


       void outputConfig(int idO, float higherThan, float lowerThan);
       void outputConfig(int idO, float refer1, int limit1);
       void outputConfig(int idO, char const* name);
       void outputShow(int idV, float var);
       void outputShow(String varName[], String value[], int length, int idO);

       void lcdTime(unsigned long interval);

        int outputType[10];
        int lcdnum=0;
        int webnum=0;
        unsigned long currentMillisView=0;
        unsigned long previousMillis = 0;

       private:

       int idOutput=0;
       int next;
       int actual;
       unsigned long _interval=3000;
       void * pvOutput[10];
       char const* _server;
       char const* _url;
       char const* _urlMail;
       char const* _serverMail;


};
#endif
