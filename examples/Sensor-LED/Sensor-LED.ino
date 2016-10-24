//Ejemplo para usar una alerta LED a partir de la lectura del sensor
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain

//Incluir las librerías sensor.h y view.h
#include <sensor.h>
#include <view.h>

//Inicializar un objeto tipo view indicando el dispositivo a usar (LED) y el pin de conexion

//view vista(LED, Pin);
view vista(LED, 3);

/*Declarar un objeto tipo sensor indicando el sensor a usar y el pin que recibe los datos del sensor
 sensor sens(tipoSensor, Pin); */

sensor sens(DHT11, 4);
//sensor sens(DHT22, 4);
//sensor sens(LM35, 4);
//sensor sens(LM335, 4);
void setup() {


}

void loop() {

  /* Lectura del sensor indicando  la variable (TEMPERATURE o HUMIDITY) para el caso de DHTxx y la unidad
  C: Celsius
  F: Fahrenheit
  K: Kelvin
  float cel=sens.read(variable, unidad); //DHTxx 
  float cel=sens.read(unidad);// LM35, LM335 */

  float cel = sens.read(TEMPERATURE, K); //DHTxx leer temperatura
  float hum = sens.read(HUMIDITY); //DHTxx leer humedad
  //float cel=sens.read(K); //LM35, LM335 leer temperatura


  /* Se llama la funcion show para encender el LED en los valores indicados
  vista.show(Referencia, Mayor_O_Menor, variable); //un limites
  vista.show(mayorque, menorque, var); //dos limite */

  //para usar dos limites en primer lugar se establecen los limites de encendido y apagado del LED
  int limite1 = 5; //encender cuando sea mayor a 5
  int limite2 = 10; // encnerder cuando sea menor a 10
  // luego se escoge la variable a comparar (cel)

  vista.show(limite1, limite2, cel); //dos limites

  /*para usar dos limites en primer lugar se establece el limite de encendido y apagado del LED
  en segundo luguar se establece si el led encendera bajo este rango o sobre este rango (HIGHER o LOWER)
  en tercer lugar se ingresa la variable que se desea comparar */

 // vista.show(limite1, HIGHER, cel); //un limite
 
 //el led puede ser sustituido por cualquier dispositivo que se active con 5v
}
