class Push_Button {
  private:
      static const int max_count = 1000;
      static int low_state_count;
      static int high_state_count;
      bool previous_state;
      byte port;
  public:
      Push_Button(const byte port){
        this->port = port;
        previous_state = true;
      }
      bool read(){
        bool state = digitalRead(port);
        if(!state){
          low_state_count++;
          high_state_count = 0;
        }else{
          low_state_count = 0;
          high_state_count++;
        }
        if(high_state_count > max_count){
          previous_state = false;
        }
        if(low_state_count > max_count && !previous_state){
          //low_state_count = 0;
          previous_state = true;
          return true;
        }else{
          return false;
        }
      }
      /*bool read(){
        bool result = false;
        bool state = digitalRead(port);
        if( !state && previous_state ){
            result = true;
        }
        previous_state = state;
        return result;
      }*/
};
int Push_Button::low_state_count = 0;
int Push_Button::high_state_count = 0;

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
