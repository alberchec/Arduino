#include <Cap_sensor.h>

Cap_sensor::Cap_sensor(uint8_t send_pin,uint8_t receive_pin,unsigned int thld){
	sensor = new CapacitiveSensor(send_pin,receive_pin)
	threshold = thld;
}

bool Cap_sensor::signal_processing(){
  const int dt = 2;
  const int it = threshold; //around 500
  const float leakage = 0.9;
  long raw = sensor->capacitiveSensorRaw(30);
  static long last_raw = raw;
  static long last_integ = 0;

  long dev = raw - last_raw;
  long integ;

  if(abs(dev) > dt){
    integ = last_integ + dev;
  }else{
    integ = last_integ;
  }
  
  if(integ > it){
    //last_integ = integ;
    return true;
  }else{
    last_integ = integ * leakage;
  }
  return false;
}

Cap_sensor::set_threshold(unsigned int thld){
	threshold = thld;
}