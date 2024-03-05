#include <vector>
#include "game.h"
#include "block/block.h"
#include "block/blocks.cpp"
#include "grid/grid.h"
#include <Arduino.h>
#include "position/position.h"
#include "keyboard/keyboard.h"

#define LEFT    16
#define RIGHT   17
#define ROTATE  18
#define DOWN    19

Game::Game() {
  grid = Grid();
  blocks = getAllBlocks();
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
  keyboard = Keyboard();
  gameOver = false;
  score = 0;

  keyboard.begin(LEFT, RIGHT, ROTATE, DOWN);
}

void Game::handleInput() {
  int buttonPressed = keyboard.readInput();

  if (buttonPressed == 1) {
    Serial.println("LEFT button pressed");
    moveBlockLeft();
  } else if (buttonPressed == 2) {
    Serial.println("RIGHT button pressed");
    moveBlockRight();
  } else if (buttonPressed == 3) {
    Serial.println("ROTATE button pressed");
    rotateBlock();
  } else if (buttonPressed == 4) {
    Serial.println("DOWN button pressed");
  }
}

Block Game::getRandomBlock() {
  if(blocks.empty()) {
    blocks = getAllBlocks();
  }

  int randomIndex = random(0, blocks.size());
  Block block = blocks[randomIndex];

  blocks.erase(blocks.begin() + randomIndex);
  return block;
}

std::vector<Block> Game::getAllBlocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw() {
  moveBlockDown();

  grid.writeBlock(currentBlock);
}

bool Game::blockFits() {
  std::vector<Position> positions = currentBlock.getCellPositions();

  for(Position position : positions){
    if(grid.isCellEmpty(position.row, position.column) == false) {
      return false;
    }
  }
  return true;
}

bool Game::isBlockOutside() {
  std::vector<Position> positions = currentBlock.getCellPositions();

  for(Position position : positions){
    if(grid.isCellOutside(position.row, position.column)) {
      return true;
    }
  }
  return false;
}

void Game::moveBlockLeft() {
  Serial.println("moving Block Left");
  if (!gameOver){
    currentBlock.move(0, -1);
    if (isBlockOutside() || blockFits() == false) {
      currentBlock.move(0, 1);
    }
    grid.writeBlock(currentBlock);
  }
}

void Game::moveBlockRight() {
  if (!gameOver){
    currentBlock.move(0, 1);
    if (isBlockOutside() || blockFits() == false) {
      currentBlock.move(0, -1);
    }
    grid.writeBlock(currentBlock);
  }
}

void Game::rotateBlock() {
  Serial.println("rotating Block");
  if (!gameOver) {
    currentBlock.rotate();

    if (isBlockOutside() || blockFits() == false) {
      currentBlock.undoRotation();
    }
  }
}

void Game::moveBlockDown() {
  if (!gameOver) {
    currentBlock.move(-1, 0);
    if (isBlockOutside() || blockFits() == false) {
      currentBlock.move(1, 0);

      lockBlock();
    }
  }
}

void Game::changeToNextBlock() {
  currentBlock = nextBlock;
  moveBlockDown();

  if (blockFits() == false) {
    Serial.println("Game Over");
    Serial.println("Game Over");
    Serial.println("Game Over");
    Serial.println("Game Over");
    Serial.println("Game Over");
    Serial.println("Game Over");
    Serial.println("Game Over");  
    gameOver = true;
  }

  nextBlock = getRandomBlock();
}

void Game::lockBlock() {
  std::vector<Position> positions = currentBlock.getCellPositions();

  for(Position position : positions) {
    grid.grid[position.row][position.column] = currentBlock.id;
  }

  changeToNextBlock();

  int rowsCleared = grid.clearFullRows();

  Serial.print("rowsCleared: ");
  Serial.println(rowsCleared);

  // LOGICA P LIMPAR AS ROWS FULL
}