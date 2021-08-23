#include <Push_button.h>

Push_button pb(7);
bool led_state = false;

void setup() {
  pinMode(8,OUTPUT);

}

void loop() {
  if(pb.read()){
    led_state = !led_state;
  }

  if(led_state) digitalWrite(8,HIGH);
  else          digitalWrite(8,LOW);

}
