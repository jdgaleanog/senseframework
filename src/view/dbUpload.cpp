
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
Serial.println("DB");
Serial.println(serverdb);
Serial.println(urldb);
Serial.println(_minuteInterval);
}

void dbUpload::dataUpload( String varName[], String value[], int varLength)
{

   // timer = millis();
    //LimitC=0;
    int i=0;
    EthernetClient client;
    Serial.println("-> Connecting...");
		Serial.println(serverdb);
		Serial.println(urldb);
		Serial.println(_minuteInterval);
    if (client.connect(serverdb, 80)) {
      Serial.println("-> Connected");
			Serial.println(serverdb);
			Serial.println(urldb);
      // Make a HTTP request:
      //client.print( "GET /test_2/add_data2.php?");
      client.print( "GET ");
      client.print(urldb);

      for(i=0; i<=(varLength-1); i++)
      {
        client.print(varName[i]);
				Serial.println(varName[i]);
        client.print("=");
				Serial.println("=");
        client.print(value[i]);
				Serial.println(value[i]);
        if (i!=varLength-1)
        {
          client.print("&");
					Serial.println("&");
        }

      }

      client.println( " HTTP/1.1");
      client.print( "Host: " );
      client.println(serverdb);
      client.println( "Connection: close" );
      client.println();
      client.println();
      //client.stop();
      _sent=1;
    }
    else {
      // you didn't get a connection to the server:
      Serial.println("--> connection failed/n");
    }


    while(_sent==1){
     //Serial.print("ciclo");
    // Serial.print("\t");
    if (client.available()) {
        char c = client.read();
        Serial.print(c);

     }
      if (!client.connected()) {

        Serial.println("disconnecting.");
        client.stop();
        _sent=0;
      }
      //LimitC=LimitC+1;
  }// fin del while

    //  Serial.print("Time: ");
    //  Serial.println(timer);

    delay(_minuteInterval*60000);

    //prints time since program started

    // wait a second so as not to send massive amounts of data
    //delay(1000);


}
