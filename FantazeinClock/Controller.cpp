#include "string.h"
#include "Controller.h"
#include "CommonFunctions.h"

Controller::Controller()
{
}
Controller::~Controller()
{
}
//--------------------------------------------------------------------------------
void Controller::Init()
{
  mm.Init(MOVING_MECHANISM_PIN_1, MOVING_MECHANISM_PIN_2);
  //-----------------------------
  Leds[0].Init(D0);
  Leds[1].Init(D1);
  Leds[2].Init(D2);
  Leds[3].Init(D3);
  Leds[4].Init(D4);
  Leds[5].Init(D5);
  Leds[6].Init(D6);
  //-----------------------------
  Initialized = true;
}
//--------------------------------------------------------------------------------
void Controller::FillLineOfTextData(String str)
{
  if (!Initialized) return;
  memset(LineOfTextData[LineOfTextDataToWriteTo], 0, LineOfTextDataLength);
  for(int16_t i = 0; i < str.length(); i++)
  {
    for(int16_t j = 0; j < font_5x7_letter_length; j++)
    {
      int16_t lineOfTextDataIdx = i * (font_5x7_letter_length + 1) + j;
      if (lineOfTextDataIdx < LineOfTextDataLength)
      {
        int8_t current_char = str.c_str()[i];
        int8_t current_char_in_font = current_char - font_5x7_first_char;
        LineOfTextData[LineOfTextDataToWriteTo][lineOfTextDataIdx] = pgm_read_byte_near((uint8_t*)font_5x7 + current_char_in_font * font_5x7_letter_length + j);
      }
    }
  }
  int8_t temp = LineOfTextDataToWriteTo;
  LineOfTextDataToWriteTo = LineOfTextDataToReadFrom;
  LineOfTextDataToReadFrom = temp;
}
//--------------------------------------------------------------------------------
void Controller::MoveLightingLeds()
{
  if (!Initialized) return;
  //-----------------------------
  if (ColumnsCounter == ColumnsCounterToMoveLeftToRight) mm.MoveLeftToRight();
  if (ColumnsCounter == ColumnsCounterToMoveRightToLeft) mm.MoveRightToLeft();
  //-----------------------------
  SlidingWindowData = LineOfTextData[LineOfTextDataToReadFrom] + SlidingWindowDataOffset;
  //-----------------------------
  if ((ColumnsCounter >= ColumnsCounterToScanLeftToRight) && 
      (ColumnsCounter < ColumnsCounterToScanLeftToRight + SlidingWindowColumnsNumber) &&
      (!(ColumnsCounter & 1)))
  {
    LightingLeds(SlidingWindowData[(ColumnsCounter - ColumnsCounterToScanLeftToRight) >> 1]);
  }
  else if ((ColumnsCounter >= ColumnsCounterToScanRightToLeft) && 
           (ColumnsCounter < ColumnsCounterToScanRightToLeft + SlidingWindowColumnsNumber) &&
           (!(ColumnsCounter & 1)))
  {
    #ifdef SHOW_LEFT_TO_RIGHT_ONLY
      LightingLeds(0);
    #else
      LightingLeds(SlidingWindowData[(((SlidingWindowColumnsNumber - 1) - (ColumnsCounter - ColumnsCounterToScanRightToLeft)) >> 1)]);
    #endif

  }
  else
  {
    LightingLeds(0);
  }
  //-----------------------------
  if(AdvanceSlidingWindowPositionCounter == 0)
  {
    if (SlidingWindowPositionStepsCounter > 0)
    {
      increment_modulo(SlidingWindowDataOffset, LineOfTextDataLength - SlidingWindowDataLength);
      SlidingWindowPositionStepsCounter--;
      if (SlidingWindowPositionStepsCounter == 0) increment_modulo(AdvanceManagerIdx, AdvanceManagerLength);
    }
  }
  //-----------------------------
  if (AdvanceManagerCounter == AdvanceManagerDelay[AdvanceManagerIdx])
  {
    SlidingWindowPositionStepsCounter = AdvanceManagerLettersSteps[AdvanceManagerIdx] * (font_5x7_letter_length + 1);
    AdvanceManagerCounter = 0;
  }
  //-----------------------------
  increment_modulo(ColumnsCounter, ColumnsCounterWholeCycle);
  increment_modulo(AdvanceSlidingWindowPositionCounter, AdvanceSlidingWindowPositionNumber);
  if (SlidingWindowPositionStepsCounter == 0) AdvanceManagerCounter++;
}
//--------------------------------------------------------------------------------
int32_t Controller::GetTimerValue()
{
  return TimerValue;
}
//--------------------------------------------------------------------------------
void Controller::LightingLeds(uint8_t leds)
{
  if (!Initialized) return;
  for(int16_t i = 0; i < 7; i++)
  {
    Leds[i].SetLed(leds & (1 << (i + 1)));
  }
  //PrintLeds(leds);
}
//--------------------------------------------------------------------------------
void Controller::PrintLineOfTextData()
{
  if (!Initialized) return;
  Serial.println("-------------------------------------------");
  for(int16_t i = 0; i < LineOfTextDataLength; i++)
  {
    for(int16_t j = 0; j < 8; j++)
    {
      Serial.print((LineOfTextData[LineOfTextDataToReadFrom][i] & (1 << j)) ? "* " : "  ");
    }
    Serial.println();
  }
}
void Controller::PrintSlidingWindowData()
{
  if (!Initialized) return;
  Serial.println("-------------------------------------------");
  for(int16_t i = 0; i < SlidingWindowDataLength; i++)
  {
    for(int16_t j = 0; j < 8; j++)
    {
      Serial.print((SlidingWindowData[i] & (1 << j)) ? "* " : "  ");
    }
    Serial.println();
  }
}
void Controller::PrintLeds(uint8_t leds)
{
  if (!Initialized) return;
  for(int16_t i = 0; i < 8; i++)
  {
    Serial.print((leds & (1 << i)) ? "* " : "  ");
  }
  Serial.println();  
}  