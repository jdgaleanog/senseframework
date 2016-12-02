#include "senseframework.h"
#include "Ethernet.h"
#include "SPI.h"
#include "LiquidCrystal.h"

sense refrigerador;
int pin=4; 
int idLM1 =0;
int idLM2 =0;  
int  idLED1=0;
int  idLED2=0;
int turno=1;
unsigned long previousMillis = 0;     
const long interval = 1000;    
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  
 //idDHT = refrigerador.sensorSelect(DHT11, pin); 
 idLM1 = refrigerador.sensorSelect(LM335, 3); 
 idLM2 = refrigerador.sensorSelect(DHT11, 4); 
  refrigerador.sensorConfig(idLM1, C);
  refrigerador.sensorConfig(idLM2, TEMPERATURE, C);
  
 idLED1=refrigerador.outputSelect(LED, 1);
 idLED2=refrigerador.outputSelect(LED, 13);


  refrigerador.connectSV(idLM1, idLED1);
  refrigerador.connectSV(idLM2, idLED1);
 
  
 lcd.begin(16,2);
 lcd.setCursor(0,2);
 lcd.print("timer:");


}

void loop() {
unsigned long currentMillis = millis();
  refrigerador.run();  
 if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    
if(turno==1){
   lcd.begin(16,2);
   lcd.setCursor(0,2);
   lcd.print("timer:");
   lcd.setCursor(0,0);
   lcd.print(refrigerador.value[1]);
   previousMillis = currentMillis;  
   turno=0;
}

else{
    
      lcd.begin(16,2);
   lcd.setCursor(0,2);
   lcd.print("timer:");
   lcd.setCursor(0,0);
   lcd.print(refrigerador.value[0]);
   previousMillis = currentMillis;  
   turno=1;
    }
 }
}

