#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led
{
private:
  uint8_t Pin;
  bool Initialized = false;
public:
  Led();
  virtual ~Led();
  void Init(uint8_t pin);
  void On();
  void Off();
  void SetLed(int8_t led_state);
};

#endif //Led_h