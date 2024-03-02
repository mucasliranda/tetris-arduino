#pragma once
#include <cstdint>
#include <vector>
#include "block/block.h"
#include <FastLED.h>
#include "led.cpp"

class Grid {
  public:
    Grid();
    void begin();
    std::vector<std::vector<int>> grid;
    void draw();
    void writeBlock(Block block);

  private:
    std::vector<int> colors;
    int numRows;
    int numCols;
    Led strip;
};
