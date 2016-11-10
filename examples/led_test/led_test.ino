#include "senseframework.h"

sense refrigerador;
int pin=11;
int idDHT = 0; 


void setup() {
  
 idDHT = refrigerador.sensor(DHT11, pin); 

}

void loop() {
  
 // refrigerador.run();
}
