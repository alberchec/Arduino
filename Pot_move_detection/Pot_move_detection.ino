void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  static int sum = 0;
  static int prev_pot = 250;
  static unsigned long last = 0;
  static byte counter = 0;
  static byte counter2 = 0;
  static bool pot_state = false;
  
  bool raw_state;
  
  if( (millis() - last) > 20 ){
    int pot = analogRead(A0);
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

  
  if(pot_state){
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(8,LOW);
  }
}
