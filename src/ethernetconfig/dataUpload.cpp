
#include "ethernetconfig.h"
#include "Arduino.h"

void dbUpload::dataUpload(char server[], char url[], String varName[], String value[], int varLength, float minuteInterval)
{

   // timer = millis();
    //LimitC=0;
    int i=0;
    EthernetClient client;
    Serial.println("-> Connecting...");
    if (client.connect(server, 80)) {
      Serial.println("-> Connected");
      // Make a HTTP request:
      //client.print( "GET /test_2/add_data2.php?");
      client.print( "GET ");
      client.print(url);

      for(i=0; i<=(varLength-1); i++)
      {
        client.print(varName[i]);
        client.print("=");
        client.print( value[i] );
        if (i!=varLength)
        {
          client.print("&");
        }

      }

      client.println( " HTTP/1.1");
      client.print( "Host: " );
      client.println(server);
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
        Serial.println();
        Serial.println("disconnecting.");
        client.stop();
        _sent=0;
      }
      //LimitC=LimitC+1;
  }// fin del while

    //  Serial.print("Time: ");
    //  Serial.println(timer);

    delay(minuteInterval*60000);

    //prints time since program started

    // wait a second so as not to send massive amounts of data
    //delay(1000);


}
