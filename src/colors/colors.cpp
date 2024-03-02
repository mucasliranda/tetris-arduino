#include <FastLED.h>
#include <cstdint>
#include "colors.h"



const int black = 0x000000;
const int darkGrey = 0x1A1F28;
const int green = 0x2FE617;
const int red = 0xE81212;
const int orange = 0xE27411;
const int yellow = 0xEDEA04;
const int purple = 0xA600F7;
const int cyan = 0x15CCD1;
const int blue = 0x0D40D8;
const int lightBlue = 0x3B55A2;
const int darkBlue = 0x2C2C7F;

std::vector<int> getCellColors() {
  return {
    // black, 
    darkGrey, green, red, orange, yellow, purple, cyan, blue
  };/*0       1        2     3      4       5       6      7     8 */
}