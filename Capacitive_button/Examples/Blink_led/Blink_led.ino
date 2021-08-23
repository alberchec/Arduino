#include <Capacitive_button.h>

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
