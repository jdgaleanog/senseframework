
#include "Arduino.h"

#include "view.h"





view::view(int type, uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{

//	init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);

  _rs=rs;
  _rw=rw;
  _enable=enable;
  _d0=d0;
  _d1=d1;
  _d2=d2;
  _d3=d3;
  _d4=d4;
  _d5=d5;
  _d6=d6;
  _d7=d7;
  _type=type;

	initview(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
//	begin(16,2);

  //Init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

view::view(int type, uint8_t rs, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  //init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);

  _rs=rs;
  _enable=enable;
  _d0=d0;
  _d1=d1;
  _d2=d2;
  _d3=d3;
  _d4=d4;
  _d5=d5;
  _d6=d6;
  _d7=d7;
  _type=type;
	//begin(16,2);
	initview(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);
  //Init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

view::view(int type, uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  //init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);

  _rs=rs;
  _rw=rw;
  _enable=enable;
  _d0=d0;
  _d1=d1;
  _d2=d2;
  _d3=d3;
  _type=type;

	initview(rs, rw, enable, d0, d1, d2, d3);

	//begin(16,2);
  //Init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

view::view(int type, uint8_t rs,  uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  //init(1, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);

  _rs=rs;
  _enable=enable;
  _d0=d0;
  _d1=d1;
  _d2=d2;
  _d3=d3;
  _type=type;
//	begin(16,2);
initview(rs,  enable, d0, d1, d2, d3);
  //Init(1, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

view::view(int type, int pin)

{
  _pin=pin;
	_type=type;
  initview(_pin);
}
