#include <Capacitive_button.h>

Capacitive_button::Capacitive_button(uint8_t send_pin, uint8_t receive_pin,const int thrsld){
  sensor = new CapacitiveSensor(send_pin,receive_pin);
  threshold = thrsld;
}

bool Capacitive_button::read(){
  raw_state = signal_processing();

  return Button_base::read();
}

void Capacitive_button::set_threshold(int thld){
  threshold = thld;
}

bool Capacitive_button::signal_processing(){
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