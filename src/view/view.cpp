
#include "Arduino.h"

#include "view.h"



int view::outputSelect(int type, uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{

//	init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);

	outputType[idOutput]=type;
	initview(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
	return idOutput-1;

//	begin(16,2);

  //Init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

int view::outputSelect(int type, uint8_t rs, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  //init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);

	//begin(16,2);
	outputType[idOutput]=type;
	initview(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);
	return idOutput-1;
  //Init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

int view::outputSelect(int type, uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  //init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);

	outputType[idOutput]=type;
	initview(rs, rw, enable, d0, d1, d2, d3);
	return idOutput-1;


	//begin(16,2);
  //Init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

int view::outputSelect(int type, uint8_t rs,  uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  //init(1, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);

//	begin(16,2);
outputType[idOutput]=type;
initview(rs,  enable, d0, d1, d2, d3);
return idOutput-1;

  //Init(1, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

int view::outputSelect(int type, int pin)

{
  //outputType[idOutput]=type;
  //outputPin1[idOutput]=pin1
  initview(type,pin);
  return idOutput-1;

}

void view::lcdTime(unsigned long interval)

{
_interval=interval;

}
