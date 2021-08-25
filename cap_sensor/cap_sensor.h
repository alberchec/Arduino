#ifndef CAP_SENSOR
#define CAP_SENSOR

#include <CapacitiveSensor.h>
#include <Arduino.h>

class Cap_sensor{
private:
	CapacitiveSensor* sensor;
	unsigned int threshold;
public:
	Cap_sensor(uint8_t,uint8_t,unsigned int);
	bool signal_processing();
	void set_threshold(unsigned int);
};

#endif