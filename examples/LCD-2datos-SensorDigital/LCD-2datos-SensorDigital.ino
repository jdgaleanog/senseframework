//Ejemplo para usar las librerías de LCD 16x2 y sensores digitales
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain


//Incluir la librería senseframework.h

#include "senseframework.h"

//Declarar un objeto tipo sense
sense refrigerador;


//Inicializar las variables a implementar, tales como pines e identificadores (idLM1, idLED1, idDHT1, idDHT2) dependiendo del tipo de sensor o elemento a usar.
int idDHT1=0;
int idDHT2=0;
int idLCD1=0;
int idLCD2=0;

void setup() {

//Llamar la función sensorSelect por medio del objeto refrigerador declarando el tipo de sensor digital (DHT11, DHT22) y el pin, esto se usa para retornar un número de
//identificación (idDHT) que se implementa en diversas funciones.

 //idLM1 = refrigerador.sensorSelect(tipoSensor, pin);
 idDHT1 = refrigerador.sensorSelect(DHT11, 1);
 idDHT2 = refrigerador.sensorSelect(DHT11, 1);

//Por medio de la función sensorConfig, ingresar el número de identificación del sensore que se quiere configurar, la variable a sensar (TEMPERATURE Ó HUMIDITY) y en caso
//de seleccionar TEMPERATURE la unidad en la que se requiere la información (C,F o K)


 //refrigerador.sensorConfig(idSensor, variable, unidad);
 refrigerador.sensorConfig(idDHT1, TEMPERATURE , C);
 refrigerador.sensorConfig(idDHT2, HUMIDITY , C);

//Llamar la función outputSelect por medio del objeto refrigerador e ingresar el dispositivo de salida (LCD para este caso) y los pines de salida, donde retorna el número de identificación para
//implementar más adelante.

//  LCD RS pin to digital pin 12
//  LCD Enable pin to digital pin 11
//  LCD D4 pin t o digital pin 10
//  LCD D5 pin to digital pin 9
//  LCD D6 pin to digital pin 8
//  LCD D7 pin to digital pin 7

// idLCD1=refrigerador.outputSelect(LCD, RS, Enable, D4, D5, D6, D7);
idLCD1=refrigerador.outputSelect(LCD, 12, 11, 10, 9, 8, 7);


//A partir de la función outputConfig enviar el número de identificación del LCD y el nombre a visualizar en el LCD.

refrigerador.outputConfig(idLCD1, "temperatura");
refrigerador.outputConfig(idLCD2, "humedad");


//Por medio del objeto refrigerador llamar la función connectSV para conectar el sensor con la vista, ingresar en ella el número de identificación de los sensores y los dispositivos
//de salida implementados.

refrigerador.connectSV(idDHT1, idLCD1);
refrigerador.connectSV(idDHT2, idLCD2);
  //refrigerador.connectSV(idDHT1, idLCD1);
  //refrigerador.connectSV(idDHT2, idLCD2);

  //configurar el tiempo en el que se va a mostrar cada dato en el LCD
  //refrigerador.lcdTime(TiempoEnMilisegundos);
refrigerador.lcdTime(3000);

//Correr el objeto de la siguiente manera:
}
void loop() {
  refrigerador.run();
}
