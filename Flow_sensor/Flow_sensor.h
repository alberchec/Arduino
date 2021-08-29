#ifndef FLOW_SENSOR
#define FLOW_SENSOR

#include <util/atomic.h>
#include <Arduino.h>

class Flow_sensor{
private:
	byte port;
	float volume = 0;
	float flow_rate = 0; 
	//volatile unsigned int pulses;
	//static void isr();
public:
	Flow_sensor(byte);
	void update();
	float get_volume();  //Liters
	void clear_volume();
	bool get_flow_status();
	float get_flow_rate(); //Liters/hour
};
//volatile unsigned int Flow_sensor::pulses = 0;

namespace FlowSensor{
	static volatile unsigned int pulses = 0;
	static void isr();
}

#endif
