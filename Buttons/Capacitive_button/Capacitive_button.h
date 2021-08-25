#ifndef CAPACITIVE_BUTTON
#define CAPACITIVE_BUTTON

#include <Cap_sensor.h>
#include <Button_base.h>

class Capacitive_button : public Button_base, public Cap_sensor{
  public:
    Capacitive_button(uint8_t,uint8_t,unsigned int);
    bool read();
};

#endif
