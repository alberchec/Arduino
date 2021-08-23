#include <Capacitive_button.h>

Capacitive_button::Capacitive_button(uint8_t send_pin, uint8_t receive_pin,const int thrsld){
  sensor = new CapacitiveSensor(send_pin,receive_pin);
  threshold = thrsld;
}

bool Capacitive_button::read(){
  unsigned long sensorValue = sensor->capacitiveSensor(30);
  
  if(sensorValue > threshold) raw_state = true;
  else                        raw_state = false;

  return Button_base::read();
}