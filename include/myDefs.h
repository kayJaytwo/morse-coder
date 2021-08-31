
/* 
    The length of a dot is 1 time unit.
    A dash is 3 time units.
    The space between symbols (dots and dashes) of the same letter is 1 time unit.
    The space between letters is 3 time units.
    The space between words is 7 time units.

    todo: add user text input 
    Added more text 
 */


#define TIMEUNIT 100 // one dot time
#define DASHTIME (TIMEUNIT * 3)
#define DOTTIME TIMEUNIT
#define CHARSPACE (TIMEUNIT * 3)
#define WORDSPACE (TIMEUNIT * 7)

#define DOT '.'
#define DASH '-'

#define LOOP_DELAY 3000
#ifdef STM32
    #define STM32_ON 0 // note opposite polarity of led activation
    #define STM32_OFF 1
#else
    #define STM32_ON 1 // normal polarity
    #define STM32_OFF 0
#endif
// #define LED_PIN 13
