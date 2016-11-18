#include "senseframework.h"
#include "Ethernet.h"
#include "SPI.h"
#include "LiquidCrystal.h"

sense refrigerador;
int pin=11;
int idDHT = 1; 
int idLM = 1;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  
 idDHT = refrigerador.sensorSelect(DHT11, pin); 
 idLM = refrigerador.sensorSelect(LM35, pin, pin); 
 refrigerador.outputSelect(idDHT, LED, 12);
 refrigerador.outputSelect(idDHT, LED, 13);
 
  
 lcd.begin(16,2);
 lcd.setCursor(0,2);
 lcd.print("timer:");


}

void loop() {
  lcd.setCursor(0,0);
lcd.print(idLM);
  
 // refrigerador.run();
}
