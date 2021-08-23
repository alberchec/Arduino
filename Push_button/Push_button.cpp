#include <Push_button.h>

Push_button::Push_button(byte p){
  port = p;
  pinMode(port,INPUT_PULLUP);
}

bool Push_button::read(){
  raw_state = !digitalRead(port);
  Button_base::read();
}