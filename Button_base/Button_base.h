#ifndef BUTTON_BASE
#define BUTTON_BASE

#include <Arduino.h>

class Button_base {
  private:
    byte check_msec = 5;
    byte press_msec = 50;
    byte release_msec = 50;
    unsigned long interval = 0;
    byte count;
    bool debounced_state;
    void debounce(bool&);
  protected:
    bool raw_state;
  public:
    Button_base();
    virtual bool read();
    void set_parameters(byte,byte,byte);
};
//unsigned long Button_base::interval = 0;
//byte Button_base::count = 2;

#endif
