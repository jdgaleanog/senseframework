//Ejemplo para usar las libreriías sensor y view (LCD 16x2)
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain

//Incluir las librerías sensor.h y view.h
#include <sensor.h>
#include <view.h>

//Inicializar un objeto tipo view indicando el dispositivo a usar y los pines de conexión


//  LCD RS pin to digital pin 12
//  LCD Enable pin to digital pin 11
//  LCD D4 pin t o digital pin 10
//  LCD D5 pin to digital pin 9
//  LCD D6 pin to digital pin 8
//  LCD D7 pin to digital pin 7

 
//view vista(LCD, RS, Enable, D4, D5, D6, D7);
view vista(LCD, 12, 11, 10, 9, 8, 7);

//Declarar un objeto tipo sensor indicando el sensor a usar y el pin que recibe los datos del sensor

// sensor sens(tipoSensor, Pin);  

sensor sens(DHT11, 4); 
//sensor sens(DHT22, 4);
//sensor sens(LM35, 4);
//sensor sens(LM335, 4);
void setup() {


} 

void loop() {
  // put your main code here, to run repeatedly:
//Lectura del sensor indicando  la variable (TEMPERATURE o HUMIDITY) para el caso de DHTxx y la unidad
//C: Celsius
//F: Fahrenheit
//K: Kelvin

//float cel=sens.read(variable, unidad); //DHTxx leer temperatura 
//float cel=sens.read(unidad);// LM35, LM335

float cel=sens.read(TEMPERATURE, K); //DHTxx leer temperatura 
float hum=sens.read(HUMIDITY); //DHTxx leer humedad 
//float cel=sens.read(K); //LM35, LM335 leer temperatura 


//Se llama la funcion show para mostrar los valores por medio del LCD 

//vista.show("texto1", variable1, "texto2", variable2) //dos variables 
//vista.show("texto1", variable1); //una variable 

vista.show("temp", cel, "hum", hum); //dos variables 
//vista.show("temperatura", cel); //una variable 

}


