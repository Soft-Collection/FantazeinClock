#ifndef Controller_h
#define Controller_h

#include <Arduino.h>
#include "Font.h"
#include "Led.h"
#include "MovingMechanism.h"
#include "Config.h"

class Controller
{
public:
	Controller();
	virtual ~Controller();
  //-------------------------------------------------------
  void Init();
  //-------------------------------------------------------
  void FillLineOfTextData(String str);
  //-------------------------------------------------------
  void MoveLightingLeds(); //Run on Timer Interrupt
  //-------------------------------------------------------
  int32_t GetTimerValue();
  //-------------------------------------------------------
  void PrintLineOfTextData();
  void PrintSlidingWindowData();
  void PrintLeds(uint8_t leds);
private:
  bool Initialized = false;
  //-------------------------------------------------------
  MovingMechanism mm;
  Led Leds[7];
  //-------------------------------------------------------
  static const int16_t LineOfTextLength = LINE_OF_TEXT_LENGTH;
  static const int16_t LineOfTextDataLength  = LineOfTextLength * (font_5x7_letter_length + 1);
  uint8_t LineOfTextData[2][LineOfTextDataLength] = {0,};
  volatile int8_t LineOfTextDataToWriteTo = 0;
  volatile int8_t LineOfTextDataToReadFrom = 1;  
  //-------------------------------------------------------
  static const int16_t SlidingWindowLength = SLIDING_WINDOW_LENGTH;
  static const int16_t SlidingWindowDataLength = SlidingWindowLength * (font_5x7_letter_length + 1);
  volatile uint8_t* SlidingWindowData = NULL;
  volatile int16_t SlidingWindowDataOffset = 0;
  volatile int16_t SlidingWindowPositionStepsCounter = 0;
  static const int16_t SlidingWindowColumnsNumber = SlidingWindowDataLength * 2;
  volatile int32_t AdvanceSlidingWindowPositionCounter = 0;
  static const int32_t AdvanceSlidingWindowPositionNumber = ADVANCE_SLIDING_WINDOW_POSITION_NUMBER;
  //-------------------------------------------------------
  static const int8_t AdvanceManagerLength = ADVANCE_MANAGER_LENGTH;
  int32_t AdvanceManagerDelay[AdvanceManagerLength] = ADVANCE_MANAGER_DELAY;
  int32_t AdvanceManagerLettersSteps[AdvanceManagerLength] = ADVANCE_MANAGER_LETTERS_STEPS;
  volatile int8_t AdvanceManagerIdx = 0;
  volatile int32_t AdvanceManagerCounter = 0;
  //-------------------------------------------------------
  static const int16_t ColumnsCounterWholeCycle = SlidingWindowLength * (font_5x7_letter_length + 1) * 2 * 5; //2 --> 2 half-cycles, 5 --> 2 * 2.5 --> 2 columns (dots and spaces), 2.5 is special coefficient.
  static const int16_t ColumnsCounterHalfCycle = ColumnsCounterWholeCycle / 2;
  //-------------------------------------------------------
  volatile int16_t ColumnsCounter = 0;
  static const int16_t ColumnsCounterToMoveLeftToRight = 0;
  static const int16_t ColumnsCounterToMoveRightToLeft = ColumnsCounterHalfCycle;
  //-------------------------------------------------------
  static const int16_t ColumnsCounterToScanOffset = COLUMNS_COUNTER_TO_SCAN_OFFSET;  
  static const int16_t ColumnsCounterToScanLeftToRight = ColumnsCounterToMoveLeftToRight + ColumnsCounterToScanOffset;
  static const int16_t ColumnsCounterToScanRightToLeft = ColumnsCounterToMoveRightToLeft + (ColumnsCounterHalfCycle - ColumnsCounterToScanOffset);
  //-------------------------------------------------------
  static const int32_t TimerValue = (int32_t)((double)(F_CPU / TIMER_PRESCALER / ColumnsCounterWholeCycle) / (double)RULER_RESONANCE_IN_HZ);
private:
  void LightingLeds(uint8_t leds);
};

#endif //Controller_h