#ifndef MovingMechanism_h
#define MovingMechanism_h

#include "Arduino.h"

class MovingMechanism
{
private:
  uint8_t Pin1;
  uint8_t Pin2;
  bool Initialized = false;
public:
  MovingMechanism();
  virtual ~MovingMechanism();
  void Init(uint8_t pin1, uint8_t pin2);
  void MoveLeftToRight();
  void MoveRightToLeft();
};

#endif //MovingMechanism_h