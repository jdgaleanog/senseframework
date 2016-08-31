#include "ethernetconfig.h"
#include "Arduino.h"

ethernetconfig::ethernetconfig (String url [], String varName[], String value[])
{
    _save = sizeof(url);

}

int ethernetconfig::retornar ()
{
  return _save;
}
