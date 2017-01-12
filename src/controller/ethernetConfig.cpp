#include "controller.h"
#include "Arduino.h"


void  controller::ethernetConfig ( byte mac[])
{
  _sent=0;


  #ifdef senseframeworkDEBUG
  Serial.begin(9600);
  Serial.println("hello");

  #endif

  for(int limitC=0; limitC<=4; limitC++)
  {


    if ( Ethernet.begin(mac)== 0) {

      if (limitC==3 )  {
        #ifdef senseframeworkDEBUG
        Serial.println("Failed to configure Ethernet using DHCP. Try again later");
        #endif

      }
      else {
        #ifdef senseframeworkDEBUG
        Serial.println("Failed to configure Ethernet using DHCP");
        #endif

      }

    }
  }

  #ifdef senseframeworkDEBUG
  Serial.println("Tweaking4All.com - Temperature Drone - v2.0");
  Serial.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  Serial.print("IP Address        : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask       : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  #endif
}
