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

  Serial.println("terminou de preencher o grid");
}

void Grid::draw() {
  Serial.println("desenhando grid");

  for(int row = 0; row < this -> grid.size(); row++) {
    for(int column = 0; column < this -> grid[row].size(); column++) {
      int key = row * this -> grid[row].size() + column;
      this -> strip.setPixel(key, this -> colors[grid[row][column]]);
    }
  }
  this -> strip.show();
}

void Grid::writeBlock(Block block) {
  Serial.println("escrevendo bloco no grid");
  std::vector<Position> positions = block.getCellPositions();

  for(Position position : positions) {
    int key = position.row * this -> grid[position.row].size() + position.column;
    strip.setPixel(key, this -> colors[block.id]);
  }
  this -> strip.show();
}