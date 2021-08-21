#include <avr/wdt.h>
#include <EEPROM.h>
#include "capacitive_button.h"
#include "Push_button.h"

#define s_pin 12
#define r_pin 10
#define relay_pin 4
#define thld_button 9

bool relay_state = HIGH; //High is off for this relay
unsigned long last = 0;
int threshold = 3500;

const int thld_min = 3500;
const int thld_max = 8000;

Capacitive_button cb(s_pin,r_pin,threshold);
Push_button pb(thld_button);

void setup() {
  wdt_enable(WDTO_2S);
  pinMode(relay_pin,OUTPUT);
  EEPROM.get(0,threshold);
  if(threshold < 3500 && threshold > 8000) threshold = 3500;
}

void loop() {
  wdt_reset();

  cb.set_threshold(threshold);

  if(cb.read() ){
    relay_state = !relay_state;
    last = millis();
  }

  if(!relay_state && ( (millis() - last) > 18000000) ){
    relay_state = HIGH;
  }
  
  if(relay_state) digitalWrite(relay_pin,HIGH);
  else            digitalWrite(relay_pin,LOW);

  if(pb.read() ){
    if(threshold >= thld_max){
      threshold = thld_min;
    }else{
      threshold += 250;
    }
    EEPROM.put(0,threshold);
  }

}
