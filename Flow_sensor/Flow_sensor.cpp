#include <Flow_sensor.h>

void FlowSensor::isr(){
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
    pulses++;
  }
}

Flow_sensor::Flow_sensor(byte p){
  port = p;
  pinMode(port,INPUT);
  attachInterrupt(digitalPinToInterrupt(port),FlowSensor::isr,RISING);
}

void Flow_sensor::update(){
  static unsigned long last = 0;
  if( (millis() - last) >= 1000 ){
    unsigned int puls;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
      puls = FlowSensor::pulses;
      FlowSensor::pulses = 0;
    }
    flow_rate = float(puls) / 396 * 1.14; //1.14 is correction factor
    volume += flow_rate;
    flow_rate *= 3600;
    last = millis();
  }
}

float Flow_sensor::get_volume(){
  return volume;  
}

void Flow_sensor::clear_volume(){
  volume = 0;
}

bool Flow_sensor::get_flow_status(){
 if(flow_rate > 10 ) return true;
 else                return false;
}

float Flow_sensor::get_flow_rate(){
  return flow_rate;
}