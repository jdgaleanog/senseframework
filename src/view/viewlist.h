#ifndef viewlist_h
#define viewlist_h

#include "Arduino.h"
#include "led.h"
#include "Lcd.h"
#include "alertByEmail.h"
#include "dbUpload.h"



class viewlist : public led, public Lcd, public alertByEmail, public dbUpload

{

public:
  

};




#endif
