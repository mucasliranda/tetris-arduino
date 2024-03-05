#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include "colors/colors.h"
#include "position/position.h"

class Block {
  public:
    Block();
    void move(int rows, int columns);
    std::vector<Position> getCellPositions();
    void rotate();
    void undoRotation();
    int id;
    std::map<int, std::vector<Position>> cells;
    std::vector<int> colors;
    int rowOffset;
    int columnOffset;
  private:
    int rotationState = 0;
};