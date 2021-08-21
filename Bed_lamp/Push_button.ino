#include "Push_button.h"

void Push_button::debounce(bool& result){
  bool raw_state = !digitalRead(port);
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

Push_button::Push_button(const byte port){
  this->port = port;
  debounced_state = false;
  pinMode(port,INPUT_PULLUP);
}

bool Push_button::read(){
  bool result = false;
  if( (millis() - interval) > check_msec ){
    debounce(result);
    interval = millis();
  }
  return result;
}
