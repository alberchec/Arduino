#ifndef PUSH_BUTTON
#define PUSH_BUTTON

#include <CapacitiveSensor.h>

class Capacitive_button {
  private:
    static const byte check_msec = 2;
    static const byte press_msec = 20;
    static const byte release_msec = 20;
    static unsigned long interval;
    static byte count;
    bool debounced_state;
    void debounce(bool&);
    CapacitiveSensor* sensor;
    int threshold;
  public:
    Capacitive_button(uint8_t,uint8_t,const int);
    bool read();
};
unsigned long Capacitive_button::interval = 0;
byte Capacitive_button::count = 2;

#endif
