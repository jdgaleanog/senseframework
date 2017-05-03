
#include "Arduino.h"
#include "view.h"

int view::outputSelect(int type)

	{
		switch (type) {
		case LCD:
		outputType[idOutput]=type;
		initview();
		return idOutput-1;
		break;

		case MAILALERT:
		_urlMail=MAILURL;
		_serverMail=SERVERURL;
		_email=0;
		initview(type);
		return idOutput-1;
		break;

	}

	}

int view::outputSelect(int type, uint8_t rs, uint8_t rw, uint8_t enable,
	uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
	uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
	{

		outputType[idOutput]=type;
		initview(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
		return idOutput-1;
	}

	int view::outputSelect(int type, uint8_t rs, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
		{

			outputType[idOutput]=type;
			initview(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);
			return idOutput-1;

		}

		int view::outputSelect(int type, uint8_t rs, uint8_t rw, uint8_t enable,
			uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
			{


				outputType[idOutput]=type;
				initview(rs, rw, enable, d0, d1, d2, d3);
				return idOutput-1;

			}

			int view::outputSelect(int type, uint8_t rs,  uint8_t enable,
				uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
				{

					outputType[idOutput]=type;
					initview(rs, enable, d0, d1, d2, d3);
					return idOutput-1;

				}

				int view::outputSelect(int type, int pin)

				{

					initview(type,pin);
					return idOutput-1;

				}

				void view::lcdTime(unsigned long interval)

				{
					_interval=interval;

				}


				int view::outputSelect(int type, char server[], char url[],  float minuteInterval)
				{
					_server=server;
					_url=url;

					initview(type, minuteInterval);
					return idOutput-1;
				}

				int view::outputSelect(int type,  char serverMail[], char urlMail[], char email[])

				{
					_urlMail=urlMail;
					_serverMail=serverMail;
					_email=email;
					initview(type);
					return idOutput-1;
				}
