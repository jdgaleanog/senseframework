//Ejemplo para usar las librerías Mail y sensores digitales
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain


//Incluir la librería senseframework.h

#include <senseframework.h>

//Declarar un objeto tipo sense
sense refrigerador;

//Inicializar las variables a implementar, tales como pines e identificadores (idLM1, idWEB1, idDHT1, idDHT2) dependiendo del tipo de sensor o elemento a usar.
int idLM1 =0;
int idMAIL=0;

void setup() {

//Llamar la función sensorSelect por medio del objeto refrigerador declarando el tipo de sensor digital (LM35, LM335) y el pin, esto se usa para retornar un número de
//identificación (idLM1) que se implementa en diversas funciones.

 //idLM1 = refrigerador.sensorSelect(tipoSensor, pin);
 idLM1 = refrigerador.sensorSelect(LM35, 1);

//Por medio de la función sensorConfig, ingresar el número de identificación del sensore que se quiere configurar y la unidad en la que se requiere la información (C,F o K)


 //refrigerador.sensorConfig(idSensor, unidad);
 refrigerador.sensorConfig(idLM1,  C);

//Es necesaria la mac del Arduino a implementar para la conexión a internet, por medio de la función ethernetConfig ingresar la mac.

byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };
refrigerador.ethernetConfig (mac);


//Con la función outputSelect seleccionar el dispositivo de salida, en este caso MAILALERT, ingresar la dirección del servidor y la extensión del archivo que lee los datos para almacenarlos
//en la base de datos.

idMAIL=refrigerador.outputSelect(MAILALERT, "direccionServidor", "extension");

//Ejemplo
//idMAIL=refrigerador.outputSelect(MAILALERT,  "senseframework.com",  "/correo/mail.php?" );

//Configurar el envío del correo de acuerdo a los límites que se deseen, estos deben ir en una variable tipo flotante y en el siguiente orden:


//higherThan: Mayor que, este límite asociará los valores mayores al valor asignado.
//lowerThan: Menor que, este límite asociará los valores menores al valor asignado.
//refrigerador.outputConfig(idMAIL,(float)higherThan, (float)lowerThan);

//Ej. Con temperatura en Celsius dentro de un rango

refrigerador.outputConfig(idMAIL,(float)20, (float)30);
//En el caso anterior se envía un correo en el caso de que la temperatura esté entre el rango, mayores a 20 y menores a 30.

//Ej. fuera de un rango
//refrigerador.outputConfig(idMAIL,(float)30, (float)20); // Para este caso, el correo se enviará si la temperatura es superior a 30 o inferior a 20.


//Por medio del objeto refrigerador llamar la función connectSV para conectar el sensor con la vista, ingresar en ella el número de identificación de los sensores y los dispositivos
//de salida implementados.
refrigerador.connectSV(idLM1, idMAIL);

//Correr el objeto de la siguiente manera:
}
void loop() {
  refrigerador.run();
 }
