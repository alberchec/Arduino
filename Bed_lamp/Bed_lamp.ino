#include <avr/wdt.h>
#include <Capacitive_button.h>

#define s_pin 12
#define r_pin 10
#define relay_pin 4

bool relay_state = HIGH; //High is off for this relay
unsigned long last = 0;
int threshold = 2500;

Capacitive_button cb(s_pin,r_pin,threshold);

void setup() {
  wdt_enable(WDTO_2S);
  
  pinMode(relay_pin,OUTPUT);
  digitalWrite(relay_pin,HIGH);
  
  cb.set_parameters(10,20,20);
}

void loop() {
  wdt_reset();

  if(cb.read() ){
    relay_state = !relay_state;
    last = millis();
  }

  if(!relay_state && ( (millis() - last) > 7200000) ){
    relay_state = HIGH;
  }
  
  if(relay_state) digitalWrite(relay_pin,HIGH);
  else            digitalWrite(relay_pin,LOW);

}
