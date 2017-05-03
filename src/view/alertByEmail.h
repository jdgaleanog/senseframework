#ifndef alertByEmail_h
#define alertByEmail_h
#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"


class alertByEmail
{

public:
  alertByEmail();
  void mailAlert( float var);
  void sendmail(char urlMail[]);
  void initMail(char server[], char urlMail[], char email[]);
  void configMail(float higherThan, float lowerThan);

private:

  bool flag=0;
  int _st;
  char const* _server;
  char const* _urlMail;
  char const* _email;
  float _higherThan;
  float _lowerThan;
};
#endif
