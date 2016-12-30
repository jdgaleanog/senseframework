#include "Arduino.h"
#include "view.h"


void view::initview(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)

					 {

			 		    switch (outputType[idOutput]) {

			 		        case LCD:
									{
									Lcd* viewlcd;
									viewlcd=new Lcd();
									pvOutput[idOutput]=viewlcd;
									viewlcd->initlcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
			 						viewlcd->begin(16,2);
									idOutput=idOutput+1;
								}
			 		        break;

			 		    }
			 		}


void view::initview(uint8_t rs, uint8_t enable,
 			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
 			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)

					 {

 					    switch (outputType[idOutput]) {

 					        case LCD:
									{
									Lcd* viewlcd;
									viewlcd=new Lcd();
									pvOutput[idOutput]=viewlcd;
									viewlcd->initlcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);
 									viewlcd->begin(16,2);
									idOutput=idOutput+1;
								}
 					        break;

 					    }
 					}


void view::initview(uint8_t rs, uint8_t rw, uint8_t enable,
 			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)

					 {

					     switch (outputType[idOutput]) {

					         case LCD:
									 {
									 Lcd* viewlcd;
									 viewlcd=new Lcd();
									 pvOutput[idOutput]=viewlcd;
									 viewlcd->initlcd(rs, rw, enable, d0, d1, d2, d3);
					 			 	 viewlcd->begin(16,2);
									 idOutput=idOutput+1;
								 }
					         break;

					     }
					 }


void view::initview(uint8_t rs,  uint8_t enable,
 			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)


					 {

					     switch (outputType[idOutput]) {

					         case LCD:
									 {
									 Lcd* viewlcd;
									 viewlcd=new Lcd();
									 pvOutput[idOutput]=viewlcd;
									 viewlcd->initlcd(rs, enable, d0, d1, d2, d3);
					 			 	 viewlcd->begin(16,2);
									 idOutput=idOutput+1;
								 }
					         break;

					     }
					 }




void view::initview(int type, int pin0)
{
	switch (type) {

			case LED:
			{
			led* view1;
			view1=new led();
			pvOutput[idOutput]=view1;
			view1->initled(pin0);

			outputType[idOutput]=type;
			idOutput=idOutput+1;
			}
			break;

		}
}

void view::initview(int type,  float minuteInterval)
{
	switch (type) {

		case WEB:
		{
		dbUpload* web1;
		web1=new dbUpload();
		pvOutput[idOutput]=web1;
		web1->initdbUpload(_server, _url,  minuteInterval);

		outputType[idOutput]=type;
		idOutput=idOutput+1;
		}
		break;
 }
}

void view::initview(int type)
{
	switch (type) {

		case MAIL:
		{
		alertByEmail* web1;
		web1=new alertByEmail();
		pvOutput[idOutput]=web1;
		web1->initMail(_serverMail ,_urlMail);

		outputType[idOutput]=type;
		idOutput=idOutput+1;
		}
		break;
 }
}
