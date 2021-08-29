#include <Pot_control.h>

Pot::Pot(byte p){
  port = p;
  pinMode(port,INPUT);
}

int Pot::pot_value(){
  return analogRead(port);
}

bool Pot::pot_state(){
  static int sum = 0;
  static int prev_pot = 250;
  static unsigned long last = 0;
  static byte counter = 0;
  static byte counter2 = 0;
  static bool pot_state = false;
  
  bool raw_state;
  
  if( (millis() - last) > 15 ){
    int pot = pot_value();
    sum += pot;
    last = millis();
    counter++;
  }
  
  if( counter >=5 ){
    sum /= 5;
    int result = abs(sum - prev_pot);
    if(result > 3){
      raw_state = true;
      prev_pot = sum;
    }else{
      raw_state = false;
    }
    sum = 0;
    counter = 0;

    if(raw_state == pot_state){
      counter2 = 0;
    }else{
      if(++counter2 > 2){
        pot_state = raw_state;
        counter2 = 0;
      }
    }
  }

  return pot_state;
}

float Pot::pot_ratio(){
  int v = pot_value();
  float ratio = (0.9*pot1*v - 0.1*pot2*v + 102.3*pot2) / (1023*pot2 - pot2*v);
  return ratio;
}