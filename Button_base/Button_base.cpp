#include <Button_base.h>

void Button_base::debounce(bool& result){
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

Button_base::Button_base(){
  debounced_state = false;
}

bool Button_base::read(){
  bool result = false;
  if( (millis() - interval) > check_msec ){
    debounce(result);
    interval = millis();
  }
  return result;
}