#include "arduino.h"

#include "sensor.h"
#include "lm35.h"

void sensor::init(int type, int pin0, int pin1)


{


switch (_type) {

	case LM35:

	  initlm35(_pin0);

    	break;  

	
	case LM335:
	    initlm335(_pin0);
	break;  

}
}