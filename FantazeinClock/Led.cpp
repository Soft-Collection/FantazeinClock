#include "Led.h"

Led::Led()
{
}
Led::~Led()
{
}
void Led::Init(uint8_t pin)
{
  Pin = pin;
  pinMode(Pin, OUTPUT);
  Initialized = true;
}
void Led::On()
{
  if (!Initialized) return;
  digitalWrite(Pin, HIGH);
}
void Led::Off()
{
  if (!Initialized) return;
  digitalWrite(Pin, LOW);
}
void Led::SetLed(int8_t led_state)
{
  if (!Initialized) return;
  digitalWrite(Pin, led_state);
}
