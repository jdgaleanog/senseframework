#include "senseframework.h"
#include "Ethernet.h"
#include "SPI.h"
#include "LiquidCrystal.h"

sense refrigerador;
int pin=4; 
int idLM1 =0;
int idLM2 =0;  
int  idLED=0;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  
 //idDHT = refrigerador.sensorSelect(DHT11, pin); 
 idLM1 = refrigerador.sensorSelect(LM35, pin); 
 idLM2 = refrigerador.sensorSelect(LM35, 3); 
 
 idLED=refrigerador.outputSelect(idLM1, LED, 12);
 idLED=refrigerador.outputSelect(idLM2, LED, 13);
 //refrigerador.outputConfig(idDHT, LED, 13);
 
  
 lcd.begin(16,2);
 lcd.setCursor(0,2);
 lcd.print("timer:");


}

void loop() {
  
  refrigerador.run();
   lcd.begin(16,2);
   lcd.setCursor(0,2);
   lcd.print("timer:");
   lcd.setCursor(0,0);
   lcd.print(refrigerador.calue[0]);
   delay(1000);
      lcd.begin(16,2);
   lcd.setCursor(0,2);
   lcd.print("timer:");
   lcd.setCursor(0,0);
   lcd.print(refrigerador.value[1]);
   delay(1000);
}
