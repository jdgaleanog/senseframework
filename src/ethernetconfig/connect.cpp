#include "ethernetconfig.h"
#include "Arduino.h"

void ethernetconfig::connect()
{
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("hello");

  #endif

  for(int limitC=0; limitC<=4; limitC++)
  {
    // start the Ethernet connection:

    if ( Ethernet.begin(_mac)== 0) {

        if (limitC==3 )  {
       Serial.println("Failed to configure Ethernet using DHCP. Try again later");
       for (;;)
       ;
        }
         else {
      Serial.println("Failed to configure Ethernet using DHCP");
      // no point in carrying on, so do nothing forevermore
       }

    }
  }
   // Ethernet.begin(mac);

    Serial.println("Tweaking4All.com - Temperature Drone - v2.0");
    Serial.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    Serial.print("IP Address        : ");
    Serial.println(Ethernet.localIP());
    Serial.print("Subnet Mask       : ");
    Serial.println(Ethernet.subnetMask());
    Serial.print("Default Gateway IP: ");
    Serial.println(Ethernet.gatewayIP());
}
