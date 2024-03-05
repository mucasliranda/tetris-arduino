#include <vector>
#include <Arduino.h>
#include "block/block.h"
#include "grid.h"
#include "led.cpp"
#include "position/position.h"

Grid::Grid() {
  numRows = 32;
  numCols = 8;
  colors = getCellColors();
  grid[numRows][numCols];
  strip = Led();
  begin();
}

void Grid::begin() {
  std::vector<int> tempRow;
  int row = 0;

  this -> strip.begin(
    this -> numRows, 
    this -> numCols
  );

  while(
    row < (this -> numRows * this -> numCols)
  ) {
    for(int column = 0; column < this -> numCols; column++){
      tempRow.push_back(0);
      row++;
    }
  
    this -> grid.push_back(tempRow);
    
    tempRow.clear();
  }
}

void Grid::draw() {
  for(int row = 0; row < this -> grid.size(); row++) {
    for(int column = 0; column < this -> grid[row].size(); column++) {
      int key = row * this -> grid[row].size() + column;
      this -> strip.setPixel(key, this -> colors[grid[row][column]]);
    }
  }
  this -> strip.show();
}

void Grid::writeBlock(Block block) {
  this -> draw();
  std::vector<Position> positions = block.getCellPositions();

  for(Position position : positions) {
    int key = position.row * this -> grid[position.row].size() + position.column;
    strip.setPixel(key, this -> colors[block.id]);
  }
  this -> strip.show();
}

bool Grid::isCellEmpty(int row, int column) {
  return this -> grid[row][column] == 0;
}

bool Grid::isCellOutside(int row, int column) {
  return row < 0 || row >= this -> numRows || column < 0 || column >= this -> numCols;
}

int Grid::clearFullRows() {
  int completed = 0;
  for(int row = 0; row < numRows; row++) {
    if(isRowFull(row)) {
      clearRow(row);
      completed++;
    }
    else if(completed > 0) {
      this -> draw();
      delay(50);
      moveRowDown(row, completed);
    }
  }
  return completed;
}

void Grid::moveRowDown(int row, int numRows) {
  for(int column = 0; column < numCols; column++) {
    grid[row - numRows][column] = grid[row][column];
    grid[row][column] = 0;
  }
}

bool Grid::isRowFull(int row) {
  for(int column = 0; column < numCols; column++) {
    if(grid[row][column] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::clearRow(int row) {
  for(int column = 0; column < numCols; column++) {
    grid[row][column] = 0;
  }
}
