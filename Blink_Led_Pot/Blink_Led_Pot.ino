void check_pot(){
  static int prev_pot_val = 250;
  static bool led_state = HIGH;
  int pot_val = analogRead(A0);
  int pot_dif = pot_val - prev_pot_val;
  if(pot_dif < 0 ) pot_dif *= -1;

  static unsigned long last = 0;
  const int period = 100;
  if( (millis()-last) > period ){
    if(pot_dif > 5){
      prev_pot_val = pot_val;
      led_state = !led_state;
      last = millis();
    }else if(!led_state){
      led_state = HIGH;
      last = millis();
    }
  }
  if(led_state) digitalWrite(8,HIGH);
  else          digitalWrite(8,LOW);
}

void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);

}

void loop() {
  check_pot();
}
