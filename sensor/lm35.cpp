#include "arduino.h"

#include "sensor.h"

float sensor::lm35()

{
int val = analogRead(_pin);
float mv = (val/1024.0)*5000;
float cel = mv/10;
//float farh = (cel*9)/5 + 32;

#ifdef pant
Serial.println("TEMPRATURE = ");
Serial.println(cel);

#endif // pant
delay(100);
cel=kelvin(cel);
return cel;
}
