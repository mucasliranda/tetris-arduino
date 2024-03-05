#include "colors/colors.h"
#include <Arduino.h>
#include "block.h"
#include <vector>
#include "position/position.h"

Block::Block() {
  rotationState = 0;
  colors = getCellColors();
  rowOffset = 32;
  columnOffset = 3;
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

void Block::undoRotation() {
  rotationState--;

  if(rotationState < 0) {
    rotationState = int(cells.size()) - 1;
  }
}