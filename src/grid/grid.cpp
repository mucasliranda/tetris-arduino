#include "grid.h"
#include <vector>
#include <Arduino.h>
#include "map/map.h"

Grid::Grid() {
  numRows = 12;
  numCols = 8;
  Initialize();
}

void Grid::Initialize() {
  std::vector<Map> temp;

  int row = 0;

  while(row < (numRows * numCols)) {
    for(int column = 0; column < numCols; column++){
      temp.push_back(Map(row, 0));
      row++;
    }
  
    this -> grid.push_back(temp);
    
    temp.clear();
  }

  // std::vector<std::vector<Map>> teste = {
  //   {Map(16, 0), Map(17, 0), Map(18, 0), Map(19, 0), Map(20, 0), Map(21, 0), Map(22, 0), Map(23, 0)},
  //   {Map(8, 0), Map(9, 0), Map(10, 0), Map(11, 0), Map(12, 0), Map(13, 0), Map(14, 0), Map(15, 0)},
  //   {Map(0, 0), Map(1, 0), Map(2, 0), Map(3, 0), Map(4, 0), Map(5, 0), Map(6, 0), Map(7, 0)},
  // };


  // this -> grid = teste;
}
