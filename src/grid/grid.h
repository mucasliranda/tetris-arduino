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
    bool isCellEmpty(int row, int column);
    bool isCellOutside(int row, int column);
    int clearFullRows();

  private:
    std::vector<int> colors;
    int numRows;
    int numCols;
    Led strip;
    void clearRow(int row);
    void moveRowDown(int row, int numRows);
    bool isRowFull(int row);
};
