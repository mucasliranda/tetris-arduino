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
  keyboard = Keyboard(LEFT, RIGHT, ROTATE, DOWN);
  gameOver = false;
  score = 0;
}

void Game::handleInput() {
  
}

Block Game::getRandomBlock() {
  if(blocks.empty()) {
    blocks = getAllBlocks();
  }

  int randomIndex = random(0, blocks.size());
  Block block = blocks[randomIndex];

  Serial.println("posicoes do bloco sorteado no game");
  for(Position position : block.getCellPositions()) {
    Serial.print("row: ");
    Serial.print(position.row);
    Serial.print(", column: ");
    Serial.println(position.column);
  }

  blocks.erase(blocks.begin() + randomIndex);
  return block;
}

std::vector<Block> Game::getAllBlocks() {
  return {OBlock()};
}

void Game::draw() {
  grid.draw();

  Serial.println("pos desenhar o grid");

  // delay de 5 segundos
  delay(5000);

  // grid.teste(4,4);

          Serial.println("antes de mover");

          currentBlock.toString();

          currentBlock.move(2,2);

          currentBlock.toString();

          grid.writeBlock(currentBlock);

  // currentBlock.draw(4,4);
}
