#include "senseframework.h"

sense refrigerador;

void setup() {
  int idDHT = refrigerador.sensor(DHT, 11); 
  refrigerador.show(idDHT, LED, 12);
  refrigerador.show(idDHT, LED, 13);
}

void loop() {
  refigerador.run();
}
