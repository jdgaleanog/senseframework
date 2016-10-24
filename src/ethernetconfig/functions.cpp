#include "ethernetconfig.h"
#include "Arduino.h"

void ethernetconfig::functions (int function,  char urlMail[], float higherThan, float lowerThan, float var)
{
  switch (function) {

    case MAILALERT:
    mailAlert(_server, urlMail, higherThan, lowerThan, var);
    break;

}
}

void ethernetconfig::functions (int function, char url[], String varName[], String value[], int varLength, float minuteInterval)
{
  switch (function) {

    case DATAUPLOAD:
    dataUpload(_server, url, varName, value, varLength, minuteInterval);
    break;
}
}
