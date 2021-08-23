#ifndef PUSH_BUTTON
#define PUSH_BUTTON

#include <Button_base.h>

class Push_button : public Button_base{
private:
	byte port;
public:
	Push_button(byte);
	bool read();
};

#endif
