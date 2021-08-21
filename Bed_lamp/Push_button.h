#ifndef PUSH_BUTTON
#define PUSH_BUTTON

class Push_button {
  private:
    static const byte check_msec = 5;
    static const byte press_msec = 50;
    static const byte release_msec = 50;
    static unsigned long interval;
    static byte count;
    bool debounced_state;
    byte port;
    void debounce(bool&);
  public:
    Push_button(const byte);
    bool read();
};
unsigned long Push_button::interval = 0;
byte Push_button::count = 2;

#endif
