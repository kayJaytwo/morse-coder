#include <Arduino.h>

#define STM32   // using stm32 based board?

#include "myDefs.h"
#include <morseLib.c>

char text1[] = "SOS Ken 123";

void setup()
{
  // put your setup code here, to run once:
  // initialise the pin configuration
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(112500);

  Serial.println("Morse code sender");

}

char thisChar;
// main loop
void loop()
{

  // strings are index to start at 0
  Serial.println("Morse Code for text");
  // Serial.println(text1);

  for (int charP = 0; (uint8_t)charP < strlen(text1); charP++)
  {
     thisChar = text1[charP];
    Serial.print(" ");
    Serial.print(thisChar);
   
    sendChar(thisChar);
  }

  Serial.println("\n");
  Serial.println("Completed");
  delay(LOOP_DELAY);
}
