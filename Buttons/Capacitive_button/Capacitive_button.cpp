#include <Capacitive_button.h>

Capacitive_button::Capacitive_button(uint8_t send_pin, uint8_t receive_pin,unsigned int thld) : Cap_sensor::Cap_sensor(send_pin,receive_pin,thld){}

bool Capacitive_button::read(){
  raw_state = signal_processing();
  return Button_base::read();
}