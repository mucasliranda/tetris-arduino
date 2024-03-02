#include "colors/colors.h"
#include <Arduino.h>
#include "block.h"
#include <vector>
#include "position/position.h"

Block::Block() {
  rotationState = 0;
  colors = getCellColors();
  cells[0] = {
    Position(0,0),
    Position(0,1),
    Position(1,0),  
    Position(1,1)
  };
  rowOffset = 0;
  columnOffset = 0;
}

void Block::draw(int offsetRow, int offsetColumn) {
  for(int i = 0; i < cells[id].size(); i++) {
    // escrever no grid
  }
  // strip.show();
}

void Block::move(int rows, int columns) {
  rowOffset += rows;
  columnOffset += columns;
}

std::vector<Position> Block::getCellPositions() {
  std::vector<Position> positions = cells[rotationState];
  std::vector<Position> movedPixels;

  for(Position position : positions) {
    Position newPosition = {position.row + rowOffset, position.column + columnOffset};
    movedPixels.push_back(newPosition);
  }

  return movedPixels;
}

void Block::rotate() {
  rotationState++;

  if(rotationState == int(cells.size())) {
    rotationState = 0;
  }
}

void Block::toString() {
  Serial.print("Block id: ");
  Serial.println(id);
  Serial.print("Block rotation state: ");
  Serial.println(rotationState);
  Serial.print("Block row offset: ");
  Serial.println(rowOffset);
  Serial.print("Block column offset: ");
  Serial.println(columnOffset);
}