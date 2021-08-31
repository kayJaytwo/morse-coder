#include <Arduino.h>
#include <stdio.h>
#include <ctype.h>
#include "myDefs.h"

/******************************************
 * High frequency flash if error in ascii text found
 * 
 */

void errorFlash()
{
  while (1)
  { // forever
    digitalWrite(LED_BUILTIN, STM32_OFF);
    delay(100);
    digitalWrite(LED_BUILTIN, STM32_ON);
    delay(100);
  }
}

/******************************************
 * get the morse string for the letter supplied
* 
* 
*/

const char *getMorseSymbol(char AsciiText)
{

  switch (toupper(AsciiText))
  {

  case ' ' :
    return " ";
    break;

  case '0':
    return "----";
    break;

  case '1':
    return ".----";
    break;

  case '2':
    return "..---";
    break;

  case '3':
    return "...--";
    break;

  case '4':
    return "....-";
    break;

  case '5':
    return ".....";
    break;

  case '6':
    return "-....";
    break;

  case '7':
    return "--...";
    break;

  case '8':
    return "---..";
    break;

  case '9':
    return "----.";
    break;

  case 'A':
    return ".-";
    break;

  case 'B':
    return "-...";
    break;

  case 'C':
    return "-.-.";
    break;

  case 'D':
    return "-..";
    break;

  case 'E':
    return ".";
    break;

  case 'F':
    return "..-.";
    break;

  case 'G':
    return "--.";
    break;

  case 'H':
    return "....";
    break;

  case 'I':
    return "..";
    break;

  case 'J':
    return ".---";
    break;

  case 'K':
    return "-.-";
    break;

  case 'L':
    return ".-..";
    break;

  case 'M':
    return "--";
    break;

  case 'N':
    return "-.";
    break;

  case 'O':
    return "---";
    break;

  case 'P':
    return ".--.";
    break;

  case 'Q':
    return "--.-";
    break;

  case 'R':
    return ".-.";
    break;

  case 'S':
    return "...";
    break;

  case 'T':
    return "-";
    break;

  case 'U':
    return "..-";
    break;

  case 'V':
    return "...-";
    break;

  case 'W':
    return ".--";
    break;

  case 'X':
    return "-..-";
    break;

  case 'Y':
    return "-.--";
    break;

  case 'Z':
    return "--..";
    break;

  default:
    errorFlash();
    return "";
  } // end switch
}

/******************************************
 * 
 * 
 */
void driveLed(const char *morseText)
{

  // setup a loop to get each character from the morse text
  // We need to separate words and characters ??
  // A space is 7 dot time units

  int noOfChars = strlen(morseText);

  for (int x = 0; x < noOfChars; x++)
  {
    // get the character from the string
    char morseS = morseText[x];
    if (morseS == ' ')
    { // check if we're sending new word
      delay(WORDSPACE);
      return;
    }

    digitalWrite(LED_BUILTIN, STM32_ON);

    if (morseS == DASH)
    {
      // Send a dash
      delay(DASHTIME);
    }
    
    if (morseS == DOT)
    {
      // Send a dot
      delay(DOTTIME);
    }

    digitalWrite(LED_BUILTIN, STM32_OFF);
    delay(TIMEUNIT);
  }

  // end morse character with inter letter time
  delay(CHARSPACE);
} // end

/******************************************
 * 
 * convert to morse code
 */

void sendChar(char asciiChar)
{
  const char *morseCode = getMorseSymbol(asciiChar);
  driveLed(morseCode);
}