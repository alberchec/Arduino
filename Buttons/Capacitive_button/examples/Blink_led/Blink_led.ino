#include <Capacitive_button.h>

Capacitive_button cb(7,5,500);

bool led_state = false;

void setup() {
  cb.set_parameters(10,20,20);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(cb.read() ){
    led_state = !led_state;
  }
  
  if(led_state) digitalWrite(8,HIGH);
  else          digitalWrite(8,LOW);
}
