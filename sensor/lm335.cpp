#include "arduino.h"

#include "sensor.h"

float sensor::lm335()
{
int degC = 0;              // fija los tipos de variables
float cel = 0;

 degC = analogRead(_pin);                                     // lee el pin analogico 0
 cel = (degC*5 / 1024.0 *1000/10)-273.15;     // pasa el valor de voltaje de 5V a formato
                                                                         // de Arduino -1024 valores- y lo convierte
 #ifdef pant                                                                       // a ºC de ºK a razón de 10 mV/ºK
 Serial.print( "Lectura PIN 0: " );
 Serial.print( degC );
 Serial.print( ", Temperatura: " );        // escribe en pantalla la lectura y el equivalente ºC
 Serial.print(cel);
 Serial.println( " C " );
#endif // pant


 delay( 100 );                        // espera 3 segundos para la siguiente lectura
return cel;
}
