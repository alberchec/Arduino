class Push_Button {
  private:
    static const byte check_msec = 5;
    static const byte press_msec = 50;
    static const byte release_msec = 50;
    static unsigned long interval;
    static byte count;
    bool debounced_state;
    byte port;
    void debounce(bool& result){
      bool raw_state = !digitalRead(port);
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
  public:
    Push_Button(const byte port){
      this->port = port;
      debounced_state = false;
    }
    bool read(){
      bool result = false;
      if( (millis() - interval) > check_msec ){
        debounce(result);
        interval = millis();
      }
      return result;
    }
};
unsigned long Push_Button::interval = 0;
byte Push_Button::count = 2;


bool LedState = LOW;

Push_Button p(2);

void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(8,OUTPUT);

}

void loop() {
  if(p.read()){
    LedState = !LedState;
  }

  if(LedState){
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(8,LOW);
  }
}
