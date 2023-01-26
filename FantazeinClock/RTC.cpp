#include "RTC.h"

RTC::RTC()
{
 	mSSID = STASSID; 
	mPass = STAPSK;  
}
RTC::~RTC()
{
}
void RTC::Init()
{
  configTime(MYTZ, "pool.ntp.org");
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
}
void RTC::GetTime(int8_t &hour, int8_t &minute, int8_t &second, int8_t &day, int8_t &month, int8_t &year)
{
  timeval tv;
  time_t now;  
  gettimeofday(&tv, nullptr);
  now = time(nullptr);
  hour = localtime(&now)->tm_hour;
  minute = localtime(&now)->tm_min;
  second = localtime(&now)->tm_sec;
  day = localtime(&now)->tm_mday;
  month = localtime(&now)->tm_mon + 1;
  year = localtime(&now)->tm_year - 100;
}
bool RTC::GetIsUpdated()
{
  timeval tv;
  time_t now;  
  gettimeofday(&tv, nullptr);
  now = time(nullptr);
  int year = localtime(&now)->tm_year;
  return(year != 70);
}