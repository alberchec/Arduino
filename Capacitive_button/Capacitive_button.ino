#include "capacitive_button.h"

void Capacitive_button::debounce(bool& result){
  bool raw_state;
  long sensorValue = sensor->capacitiveSensor(30);
  
  if(sensorValue > threshold) raw_state = true;
  else                        raw_state = false;

  if(raw_state == debounced_state){
    if(debounced_state) count = release_msec / check_msec;
    else                count = press_msec /check_msec;
  }else{
    if(--count == 0 ){
      debounced_state = raw_state;
      result = debounced_state;
      if(debounced_state) count = release_msec / check_msec;
      else                count = press_msec /check_msec;
    }
  }
}

Capacitive_button::Capacitive_button(uint8_t send_pin, uint8_t receive_pin,const int thrsld){
  debounced_state = false;
  sensor = new CapacitiveSensor(send_pin,receive_pin);
  threshold = thrsld;
}

bool Capacitive_button::read(){
  bool result = false;
  if( (millis() - interval) > check_msec ){
    debounce(result);
    interval = millis();
  }
  return result;
}

//Example

Capacitive_button cb(7,5,250);

bool led_state = false;

void setup() {
  pinMode(8,OUTPUT);
}

void loop() {
  if(cb.read() ){
    led_state = !led_state;
  }
  
  if(led_state) digitalWrite(8,HIGH);
  else          digitalWrite(8,LOW);
}
