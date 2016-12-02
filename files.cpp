#ifndef FILES_H
#define FILES_H

#include "src/controller/controller.cpp"
#include "src/controller/init.cpp"
#include "src/controller/read.cpp"
#include "src/controller/sensor.cpp"
#include "src/controller/sensorRead.cpp"
#include "src/controller/sensorInit.cpp"
#include "src/controller/sensorConfig.cpp"

#include "src/ethernetconfig/connect.cpp"
#include "src/ethernetconfig/dataUpload.cpp"
#include "src/ethernetconfig/ethernetconfig.cpp"
#include "src/ethernetconfig/functions.cpp"
#include "src/ethernetconfig/mailAlert.cpp"
#include "src/ethernetconfig/sendmail.cpp"

#include "src/sensor/conversion.cpp"
#include "src/sensor/dht.cpp"
#include "src/sensor/fahrenheit.cpp"
#include "src/sensor/kelvin.cpp"
#include "src/sensor/lm35.cpp"
#include "src/sensor/lm335.cpp"

#include "src/view/initview.cpp"
#include "src/view/led.cpp"
#include "src/view/Lcd.cpp"
#include "src/view/show.cpp"
#include "src/view/view.cpp"
#include "src/view/outputShow.cpp"



#endif  /* FILES_H */
