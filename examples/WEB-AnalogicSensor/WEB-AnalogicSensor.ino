//Ejemplo para usar las librerías web y sensores analogicos
// Written by Paula Andrea Faustino Trujillo y Juan David Galeano Galindo, public domain


//Incluir la librería senseframework.h

#include <senseframework.h>

//Declarar un objeto tipo sense
sense refrigerador;

//Inicializar las variables a implementar, tales como pines e identificadores (idLM1, idWEB1, idDHT1, idDHT2) dependiendo del tipo de sensor o elemento a usar.
int idLM1 =0;
int idWEB=0;


void setup() {

//Llamar la función sensorSelect por medio del objeto refrigerador declarando el tipo de sensor digital (LM35, LM335) y el pin, esto se usa para retornar un número de
//identificación (idLM1) que se implementa en diversas funciones.

 //idLM1 = refrigerador.sensorSelect(tipoSensor, pin);
 idLM1 = refrigerador.sensorSelect(LM35, 1);

//Por medio de la función sensorConfig, ingresar el número de identificación del sensore que se quiere configurar y la unidad en la que se requiere la información (C,F o K)

 //refrigerador.sensorConfig(idSensor, unidad);
 refrigerador.sensorConfig(idLM1,  C);

//Con la función sensorName asignar un nombre al sensor que anteriormente fue seleccionado con su respectivo identificador para que asi sea enviado a la pagian web.
refrigerador.sensorName(idLM1,"nombreSensor");

//Es necesaria la mac del Arduino a implementar para la conexión a internet, por medio de la función ethernetConfig ingresar la mac.

byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };
refrigerador.ethernetConfig (mac);

//Con la función outputSelect seleccionar el dispositivo de salida, en este caso WEB, ingresar la dirección del servidor, la extensión del archivo que lee los datos para almacenarlos
//en la base de datos y el tiempo de envío de la información en minutos.
//Ejemplo
//idWEB=refrigerador.outputSelect(WEB, "direccionServidor", "extension", tiempoEnvio);

idWEB=refrigerador.outputSelect(WEB,  "senseframework.com",  "/addData.php?", 5);


//Por medio del objeto refrigerador llamar la función connectSV para conectar el sensor con la vista, ingresar en ella el número de identificación de los sensores y los dispositivos
//de salida implementados ademas del nombre con el cual se va a subir la variable a la pagina web.

refrigerador.connectSV(idLM1, idWEB, "temperature");

}

//Correr el objeto de la siguiente manera:
void loop() {
  refrigerador.run();
}
