#ifndef CAPACITIVE_BUTTON
#define CAPACITIVE_BUTTON

#include <CapacitiveSensor.h>
#include <Button_base.h>

class Capacitive_button : public Button_base{
  private:
    CapacitiveSensor* sensor;
    int threshold;
  public:
    Capacitive_button(uint8_t,uint8_t,const int);
    bool read();
    void set_threshold(int);
};

#endif
