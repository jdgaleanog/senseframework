#include "alertByEmail.h"
#include "Arduino.h"


void alertByEmail::mailAlert(char server[], char urlMail[], float higherThan, float lowerThan, float var)
{
_server=server;

  if (higherThan > lowerThan) {

  if (var> higherThan) {
      sendmail(urlMail);
      }
  else if (var < lowerThan) {
      sendmail(urlMail);
      }
  else {

      }
    }

  if (higherThan < lowerThan) {

  if ((var > higherThan)&&(var < lowerThan)){
      sendmail(urlMail);
      }
  else {

      }
  }

}
