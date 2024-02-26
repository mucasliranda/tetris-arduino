#pragma once
#include <vector>
#include "map/map.h"

class Grid {
  public:
    Grid();
    void Initialize();
    std::vector<std::vector<Map>> grid;
    // Map[][] grid;

  private:
    int numRows;
    int numCols;
};
