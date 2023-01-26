#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include "Controller.h"
#include "RTC.h"
#include "Config.h"
#include "Period.h"

RTC rtc;
Period period100_1(NULL, 100, true);
Period period100_2(NULL, 100, true);

static void on_period100_1(void* instance);
static void on_period100_2(void* instance);

Controller contr;

void ICACHE_RAM_ATTR onTimerISR()
{
   cli();
   contr.MoveLightingLeds();
}

void setup() 
{
   Serial.begin(115200);
   //------------------------------------------------   
   rtc.Init();
   //------------------------------------------------   
   period100_1.AddOnPeriodExpiredHandler(on_period100_1);
   period100_2.AddOnPeriodExpiredHandler(on_period100_2);
   //------------------------------------------------
   contr.Init();
   //------------------------------------------------   
   timer1_attachInterrupt(onTimerISR);
   timer1_enable(TIM_DIV256, TIM_EDGE, TIM_LOOP);
   timer1_write(contr.GetTimerValue());
}
void loop() 
{
   int8_t hour;
   int8_t minute;
   int8_t second;
   int8_t day;
   int8_t month;
   int8_t year;
   rtc.GetTime(hour, minute, second, day, month, year);
   uint32_t TC = millis();
   bool isUpdated = rtc.GetIsUpdated();
   if (!isUpdated)
   {
      period100_1.Check(TC); //Points only.
      return;
   }
   else
   {
      period100_2.Check(TC); //Time and points.
   }
}
void on_period100_1(void* instance)
{
   contr.FillLineOfTextData("     Time      --:--     Date      --/--     ");
}
void on_period100_2(void* instance)
{
   int8_t hour;
   int8_t minute;
   int8_t second;
   int8_t day;
   int8_t month;
   int8_t year;
   rtc.GetTime(hour, minute, second, day, month, year);
   char timeStr[50];
   sprintf(timeStr, "     Time      %02d:%02d     Date      %02d/%02d     ", hour, minute, day, month);
   contr.FillLineOfTextData(timeStr);
}
