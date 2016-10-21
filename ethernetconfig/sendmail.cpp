#include "Arduino.h"
#include "alertByEmail.h"

void alertByEmail::sendmail(char urlMail[])
{
  EthernetClient client;

  if (client.connect(_server, 80)) {
    Serial.println("-> Connected");
    client.print("GET ");
    client.print("/correo/mail.php?");
    client.println(" HTTP/1.1");
    client.print( "Host: " );
    client.println(_server);
    Serial.println("-> send");
    client.println( "Connection: close" );
    client.println();
    client.println();
    _st=1;
  }
  else {
// you didn't get a connection to the server:
    Serial.println("--> connection failed/n");
  }
while(_st==1){
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
    _st=0;
  }
//LimitC=LimitC+1;
}// fin del while

}
