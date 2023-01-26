#include "MovingMechanism.h"

MovingMechanism::MovingMechanism()
{
}
MovingMechanism::~MovingMechanism()
{
}
void MovingMechanism::Init(uint8_t pin1, uint8_t pin2)
{
  Pin1 = pin1;
  Pin2 = pin2;
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  Initialized = true;
}
void MovingMechanism::MoveLeftToRight()
{
  if (!Initialized) return;
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
}
void MovingMechanism::MoveRightToLeft()
{
  if (!Initialized) return;
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
}
