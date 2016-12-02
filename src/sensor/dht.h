/* DHT.h library

MIT license
written by Adafruit Industries
*/
#ifndef dht_H
#define dht_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "functionconv.h"

// Uncomment to enable printing out nice debug messages.
//#define DHT_DEBUG

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef DHT_DEBUG
  #define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
  #define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
  #define DEBUG_PRINT(...) {}
  #define DEBUG_PRINTLN(...) {}
#endif

// Define types of sensors.
#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21
#define TEMPERATURE 5
#define HUMIDITY 6
#define F 7
#define K 8
#define C 9


class dht: public functionconv
 {
  public:
  dht();
	void initDHT(int pin, int type);
  void configDHT(int variable, int unit);
  float readDHT();
	void begin(void);
	float readTemperature(bool S=false);
	float convertCtoF(float);
	float convertFtoC(float);
	float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=true);
	float readHumidity(void);
	boolean read(void);

 private:
  uint8_t data[6];
  uint8_t _pin, _type, _bit, _port;
  uint32_t _lastreadtime, _maxcycles;
  bool _firstreading;
  bool _lastresult;
  int _variable;
  int _unit;
  float _dataReaded;

  uint32_t expectPulse(bool level);

};

class InterruptLock {
  public:
   InterruptLock() {
    noInterrupts();
   }
   ~InterruptLock() {
    interrupts();
   }

};

#endif
