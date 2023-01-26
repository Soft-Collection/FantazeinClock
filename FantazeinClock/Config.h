#ifndef Config_h
#define Config_h

#ifndef STASSID
#define STASSID "YourSSID"
#define STAPSK  "YourPassword"
#endif

//Put your time zone here: https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h
#define MYTZ TZ_America_New_York

//pins definitions for TM1637 and can be changed to other ports
#define  CLK_PIN  5 
#define  DIO_PIN  0

#define LINE_OF_TEXT_LENGTH 45;
#define SLIDING_WINDOW_LENGTH 5
#define ADVANCE_SLIDING_WINDOW_POSITION_NUMBER 150 /* How fast Sliding Window is moving. */
#define ADVANCE_MANAGER_LENGTH 5
#define ADVANCE_MANAGER_DELAY {1, 10000, 50000, 10000, 30000} /* Use values 1 and greater */
#define ADVANCE_MANAGER_LETTERS_STEPS {5, 10, 10, 10, 5}
#define COLUMNS_COUNTER_TO_SCAN_OFFSET 70
#define TIMER_PRESCALER 256
#define RULER_RESONANCE_IN_HZ 9.4
#define SHOW_LEFT_TO_RIGHT_ONLY

#define LED_0 D0
#define LED_1 D1
#define LED_2 D2
#define LED_3 D3
#define LED_4 D4
#define LED_5 D5
#define LED_6 D6

#define MOVING_MECHANISM_PIN_1 D7
#define MOVING_MECHANISM_PIN_2 D8

#endif //Config_h