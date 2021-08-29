#ifndef POT_CONTROL
#define POT_CONTROL

#include <Arduino.h>

class Pot{
private:
	byte port;
  const float pot1 = 10;
  const float pot2 = 9.25;
public:
	Pot(byte p);
	int pot_value();
  bool pot_state();
  float pot_ratio();
};

#endif
