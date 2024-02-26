#include "colors.h"
#include <Adafruit_NeoPixel.h>

const uint32_t darkGrey = Adafruit_NeoPixel::Color(26, 31, 40);
const uint32_t green = Adafruit_NeoPixel::Color(47, 230, 23);
const uint32_t red = Adafruit_NeoPixel::Color(232, 18, 18);
const uint32_t orange = Adafruit_NeoPixel::Color(226, 116, 17);
const uint32_t yellow = Adafruit_NeoPixel::Color(237, 234, 4);
const uint32_t purple = Adafruit_NeoPixel::Color(166, 0, 247);
const uint32_t cyan = Adafruit_NeoPixel::Color(21, 204, 209);
const uint32_t blue = Adafruit_NeoPixel::Color(13, 64, 216);
const uint32_t lightBlue = Adafruit_NeoPixel::Color(59, 85, 162);
const uint32_t darkBlue = Adafruit_NeoPixel::Color(44, 44, 127);

std::vector<uint32_t> GetCellColors() {
  return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

uint32_t GetRandomColor() {
  std::vector<uint32_t> colors = GetCellColors();
  return colors[random(0, colors.size())];
}