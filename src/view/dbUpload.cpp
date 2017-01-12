
#include "dbUpload.h"
#include "Arduino.h"

dbUpload::dbUpload()
{
}

void dbUpload::initdbUpload(char server[], char url[],  float minuteInterval)
{
	serverdb=server;
	urldb=url;
	_minuteInterval=minuteInterval;
	#ifdef senseframeworkDEBUG
	Serial.println("DB");
	Serial.println(serverdb);
	Serial.println(urldb);
	Serial.println(_minuteInterval);
	#endif
}

void dbUpload::dataUpload( String varName[], String value[], int varLength)
{

	currentMillis=millis();
	if (currentMillis - previousMillisdb >= (_minuteInterval*60000) )
	{

		previousMillisdb = currentMillis;
		int i=0;
		EthernetClient client;
		#ifdef senseframeworkDEBUG
		Serial.println("-> Connecting...");
		Serial.println(serverdb);
		Serial.println(urldb);
		Serial.println(_minuteInterval);
		#endif
		if (client.connect(serverdb, 80)) {
			#ifdef senseframeworkDEBUG
			Serial.println("-> Connected");
			Serial.println(serverdb);
			Serial.println(urldb);
			#endif

			client.print( "GET ");
			client.print(urldb);

			for(i=0; i<=(varLength-1); i++)
			{
				client.print(varName[i]);
				#ifdef senseframeworkDEBUG
				Serial.println(varName[i]);
				#endif
				client.print("=");
				#ifdef senseframeworkDEBUG
				Serial.println("=");
				#endif
				client.print(value[i]);
				#ifdef senseframeworkDEBUG
				Serial.println(value[i]);
				#endif
				if (i!=varLength-1)
				{
					client.print("&");
					#ifdef senseframeworkDEBUG
					Serial.println("&");
					#endif
				}

			}

			client.println( " HTTP/1.1");
			client.print( "Host: " );
			client.println(serverdb);
			client.println( "Connection: close" );
			client.println();
			client.println();

			_sent=1;
		}
		else {

			#ifdef senseframeworkDEBUG
			Serial.println("--> connection failed/n");
			#endif
		}


		while(_sent==1){

			if (client.available()) {
				char c = client.read();
				#ifdef senseframeworkDEBUG
				Serial.print(c);
				#endif
			}
			if (!client.connected()) {

				#ifdef senseframeworkDEBUG
				Serial.println("disconnecting.");
				#endif
				client.stop();
				_sent=0;
			}

		}

	}
}
