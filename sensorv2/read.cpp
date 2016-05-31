#include "arduino.h"

#include "sensor.h"
#include "lm35.h"

float sensor::read()


{


switch (_type) {

	case LM35:

	  _cel=readlm35();

    	break;  

	
	case LM335:
	    _cel=readlm335();
	break;  

}
return _cel;
}
