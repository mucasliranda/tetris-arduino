#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include "colors/colors.h"
#include "position/position.h"

class Block {
  public:
    Block();
    void draw(int offsetRow, int offsetColumn);
    void move(int rows, int columns);
    std::vector<Position> getCellPositions();
    void rotate();
    int id;
    std::map<int, std::vector<Position>> cells;
    std::vector<int> colors;
    void toString();
    int rowOffset;
    int columnOffset;
  private:
    int rotationState = 0;
};