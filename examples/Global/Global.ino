//Ejemplo para usar las librerías ... (LCD 16x2)
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain


//Incluir la librería senseframework.h

#include <senseframework.h>

//Declarar un objeto tipo sense 
sense refrigerador;

//Inicializar las variables a implementar, tales como pines e identificadores (idLM1, idLED1, idDHT1, idDHT2) dependiendo del tipo de sensor o elemento a usar. 
int idDHT =0;
int idLM1 =0;  
int idLED1=0;
int idLED2=0;
int idLCD1=0;
int idLCD2=0;
int idMAIL1=0;
int idMAIL2=0;
int idWEB=0; 



void setup() {

//Inicializar sensores
//Llamar la función sensorSelect por medio del objeto refrigerador declarando el tipo de sensor (LM35, LM335, DHT11, DHT22) y el pin, esto se usa para retornar un número de 
//identificación (idDHT) que se implementa en diversas funciones.
//idLM1 = refrigerador.sensorSelect(tipoSensor, pin); 
idDHT = refrigerador.sensorSelect(DHT22, 1); 
idLM1 = refrigerador.sensorSelect(LM35, 0); 

//Congifurar sensores
//Por medio de la función sensorConfig,
//Sensor Digital: ingresar el número de identificación del sensore que se quiere configurar, la variable a sensar (TEMPERATURE, HUMIDITY) y en caso 
//de seleccionar TEMPERATURE la unidad en la que se requiere la información (C,F o K)
 //refrigerador.sensorConfig(idSensor, variable, unidad);
//Sensor Analogo: ingresar el número de identificación del sensore que se quiere configurar,  la unidad en la que se requiere la información (C,F o K)
 //refrigerador.sensorConfig(idSensor, unidad);

refrigerador.sensorConfig(idLM1,C);
refrigerador.sensorConfig(idDHT, TEMPERATURE, C);

//Con la función sensorName asignar un nombre al sensor que anteriormente fue seleccionado con su respectivo identificador para que asi sea enviado a la pagian web.

refrigerador.sensorName(idLM1,"LM35");
refrigerador.sensorName(idDHT,"DHT22");
 
// inicializacion de vista

//Llamar la función outputSelect por medio del objeto refrigerador e ingresar el dispositivo de salida (LED, LCD, MAIL) y el pin de salida, donde retorna el número de identificación para 
//implementar más adelante.

//idLED1=refrigerador.outputSelect(LED, pin);

idLED1=refrigerador.outputSelect(LED, 3);
idLED2=refrigerador.outputSelect(LED, 4);
//  LCD RS pin to digital pin 12
//  LCD Enable pin to digital pin 11
//  LCD D4 pin t o digital pin 10
//  LCD D5 pin to digital pin 9
//  LCD D6 pin to digital pin 8
//  LCD D7 pin to digital pin 7
// idLCD1=refrigerador.outputSelect(LCD, RS, Enable, D4, D5, D6, D7);

idLCD1=refrigerador.outputSelect(LCD, 10, 9, 8, 7, 6, 5);
idLCD2=refrigerador.outputSelect(LCD, 10, 9, 8, 7, 6, 5);

//Ingresar la dirección del servidor y la extensión del archivo que lee los datos para almacenarlos
//en la base de datos.
//idMAIL=refrigerador.outputSelect(MAILALERT, "direccionServidor", "extension");

idMAIL1=refrigerador.outputSelect(MAILALERT,  "senseframework.com",  "/correo/mail.php?" );
idMAIL2=refrigerador.outputSelect(MAILALERT,  "senseframework.com",  "/correo/mail.php?" );

//Ingresar la dirección del servidor, la extensión del archivo que lee los datos para almacenarlos
//en la base de datos y el tiempo de envío de la información en minutos.
//Ejemplo
//idWEB=refrigerador.outputSelect(WEB, "direccionServidor", "extension", tiempoEnvio);

idWEB=refrigerador.outputSelect(WEB, "senseframework.com", "/addData.php?", 5);

//Configuracion de vista
//A partir de la función outputConfig se configuran los parámetros por medio de los cuales el LED se encenderá o apagará.
//Para que el LED encienda dentro o fuera de un rango implementar de la siguiente manera la función:

//Dentro de un rango: 
//refrigerador.outputConfig(idLED1,(float)higherThan, (float)lowerThan);
//Fuera de un rango:
//refrigerador.outputConfig(idLED1,(float)higherThan, (float)lowerThan);
                                     //Ej.  >30                 <20


//Para que el LED se encienda a partir de un límite en adelante (>n) implementar de la siguiente manera la función:
//refrigerador.outputConfig(idLED2,(float)20, HIGHER); 

//Para que el LED se encienda a partir de un límite hacia atrás (<n) implementar de la siguiente manera la función:
//refrigerador.outputConfig(idLED2,(float)20, LOWER); 

refrigerador.outputConfig(idLED1,(float)20, HIGHER);
refrigerador.outputConfig(idLED2,(float)20, HIGHER);    

//A partir de la función outputConfig enviar el número de identificación del LCD y el nombre a visualizar en el LCD.

refrigerador.outputConfig(idLCD1, "TemperaturaDHT"); 
refrigerador.outputConfig(idLCD2, "TemperaturaLM35"); 

//Configurar el envío del correo de acuerdo a los límites que se deseen, estos deben ir en una variable tipo flotante y en el siguiente orden:  
//higherThan: Mayor que, este límite asociará los valores mayores al valor asignado.
//lowerThan: Menor que, este límite asociará los valores menores al valor asignado.
//refrigerador.outputConfig(idMAIL,(float)higherThan, (float)lowerThan);

refrigerador.outputConfig(idMAIL1,(float)20, (float)40 );
refrigerador.outputConfig(idMAIL2,(float)20, (float)40 );


// conectar sensor y vista 

//Por medio del objeto refrigerador llamar la función connectSV para conectar el sensor con su vista correspondiente, ingresar en ella el número de identificación de los sensores 
//y los dispositivos de salida implementados, ademas para el caso de WEB el nombre con el cual se va a subir la variable a la pagina web.

refrigerador.connectSV(idDHT, idLED1);
refrigerador.connectSV(idDHT, idLCD1);
refrigerador.connectSV(idDHT, idMAIL1);
refrigerador.connectSV(idDHT, idWEB, "temperature1");

refrigerador.connectSV(idLM1, idLED2);
refrigerador.connectSV(idLM1, idLCD2);
refrigerador.connectSV(idLM1, idMAIL2);
refrigerador.connectSV(idLM1, idWEB, "temperature2");
 
//configurar el tiempo en el que se va a mostrar cada dato en el LCD
//refrigerador.lcdTime(TiempoEnMilisegundos);
refrigerador.lcdTime(3000);

// configurar web   

//Es necesaria la mac del Arduino a implementar para la conexión a internet, por medio de la función ethernetConfig ingresar la mac.

byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };     
refrigerador.ethernetConfig (mac);

}

void loop() {

  refrigerador.run();  
 

}
