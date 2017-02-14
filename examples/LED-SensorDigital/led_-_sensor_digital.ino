//Ejemplo para usar las librerías LED y sensor digital
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain


//Incluir la librería senseframework.h

#include "senseframework.h"

//Declarar un objeto tipo sense 
sense refrigerador;  


//Inicializar las variables a implementar, tales como pines e identificadores (idLM1, idLED1, idDHT1, idDHT2) dependiendo del tipo de sensor o elemento a usar. 
int idDHT=0;
int idLED1=0;

void setup() {

//Llamar la función sensorSelect por medio del objeto refrigerador declarando el tipo de sensor digital (DHT11, DHT22) y el pin, esto se usa para retornar un número de 
//identificación (idDHT) que se implementa en diversas funciones.

 //idLM1 = refrigerador.sensorSelect(tipoSensor, pin); 
 idDHT = refrigerador.sensorSelect(DHT11, 1); 

//Por medio de la función sensorConfig, ingresar el número de identificación del sensore que se quiere configurar, la variable a sensar (TEMPERATURE Ó HUMIDITY) y en caso 
//de seleccionar TEMPERATURE la unidad en la que se requiere la información (C,F o K)


 //refrigerador.sensorConfig(idSensor, variable, unidad);
 refrigerador.sensorConfig(idDHT, TEMPERATURE , C);


//Llamar la función outputSelect por medio del objeto refrigerador e ingresar el dispositivo de salida (LED para este caso) y el pin de salida, donde retorna el número de identificación para 
//implementar más adelante.

//idLED1=refrigerador.outputSelect(LED, pin);
idLED1=refrigerador.outputSelect(LED, 2);

//A partir de la función outputConfig se configuran los parámetros por medio de los cuales el LED se encenderá o apagará.
//Para que el LED encienda dentro o fuera de un rango implementar de la siguiente manera la función:

//Dentro de un rango: 
//refrigerador.outputConfig(idLED1,(float)higherThan, (float)lowerThan);
refrigerador.outputConfig(idLED1,(float)20, (float)30);
                                 //Ej.  >20        <30
                                                           
//Fuera de un rango:
//refrigerador.outputConfig(idLED1,(float)higherThan, (float)lowerThan);
                                     //Ej.  >30                 <20


//Para que el LED se encienda a partir de un límite en adelante (>n) implementar de la siguiente manera la función:
//refrigerador.outputConfig(idLED2,(float)20, HIGHER); 

//Para que el LED se encienda a partir de un límite hacia atrás (<n) implementar de la siguiente manera la función:
//refrigerador.outputConfig(idLED2,(float)20, LOWER); 


//Por medio del objeto refrigerador llamar la función connectSV para conectar el sensor con la vista, ingresar en ella el número de identificación del sensor y el dispositivo
//de salida implementados.

refrigerador.connectSV(idDHT, idLED1);

  
}
//Correr el objeto de la siguiente manera:
void loop() {
  refrigerador.run();  
    
}

