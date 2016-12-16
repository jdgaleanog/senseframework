#ifndef alertByEmail_h
#define alertByEmail_h
#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"


class alertByEmail
    {

    public:
      alertByEmail();
      void mailAlert(char server[], char urlMail[], float higherThan, float lowerThan, float var);
      void sendmail(char urlMail[]);

    private:

      int _st;
      char* _server;
    };
  #endif
