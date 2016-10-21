#include "ethernetconfig.h"
#include "Arduino.h"

ethernetconfig::ethernetconfig (char server[], byte mac[])
{

_server=server;
_sent=0;
_mac=mac;

}
