#include "alertByEmail.h"
#include "Arduino.h"

alertByEmail::alertByEmail()
	{
	}
void alertByEmail::initMail(char server[], char urlMail[])
{
	_server=server;
	_urlMail=urlMail;
}
void alertByEmail::configMail(float higherThan, float lowerThan)
{
	_higherThan=higherThan;
	_lowerThan=lowerThan;

}
void alertByEmail::mailAlert( float var)
{


  if (_higherThan > _lowerThan) {

  if (var> _higherThan) {
      sendmail(_urlMail);
      }
  else if (var < _lowerThan) {
      sendmail(_urlMail);
      }
  else {

      }
    }

  if (_higherThan < _lowerThan) {

  if ((var > _higherThan)&&(var < _lowerThan)){
      sendmail(_urlMail);
      }
  else {

      }
  }

}

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
