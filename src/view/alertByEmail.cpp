#include "alertByEmail.h"
#include "Arduino.h"

alertByEmail::alertByEmail()
{
}

void alertByEmail::initMail(char server[], char urlMail[], char email[])
{
	_server=server;
	_urlMail=urlMail;
	_email=email;
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
			if(flag==0){
				sendmail(_urlMail);
				flag=1;
			}
		}
		else if (var < _lowerThan) {
			if(flag==0){
				sendmail(_urlMail);
				flag=1;
			}
		}
		else {
			flag=0;
		}
	}

	if (_higherThan < _lowerThan) {

		if ((var > _higherThan)&&(var < _lowerThan)){
			if(flag==0){
				sendmail(_urlMail);
				flag=1;
			}
		}
		else {
			flag=0;
		}
	}

}

void alertByEmail::sendmail(char urlMail[])
{
	EthernetClient client;

	if (client.connect(_server, 80)) {
		#ifdef senseframeworkDEBUG
		Serial.println("-> Connected");
		#endif
		client.print("GET ");
		client.print(_urlMail);
		if(_email!=0)
		{
		client.print("email");
		client.print("=");
		client.print(_email);
		}
		client.println(" HTTP/1.1");
		client.print( "Host: " );
		client.println(_server);
		#ifdef senseframeworkDEBUG
		Serial.println("-> send");
		#endif
		client.println( "Connection: close" );
		client.println();
		client.println();
		_st=1;
	}
	else {

		#ifdef senseframeworkDEBUG
		Serial.println("--> connection failed/n");
		#endif
	}
	while(_st==1){

		if (client.available()) {
			char c = client.read();
			#ifdef senseframeworkDEBUG
			Serial.print(c);
			#endif
		}
		if (!client.connected()) {
			#ifdef senseframeworkDEBUG
			Serial.println();
			Serial.println("disconnecting.");
			#endif
			client.stop();
			_st=0;
		}

	}

}
