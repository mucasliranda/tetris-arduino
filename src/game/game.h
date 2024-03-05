#pragma once
#include "keyboard/keyboard.h"
#include "block/block.h"
#include "grid/grid.h"
#include <vector>

class Game {
  public:
    Game();
    void handleInput();
    bool gameOver;
    int score;
    void draw();
    Keyboard keyboard;
  
  private:
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    bool blockFits();
    bool isBlockOutside();
    void lockBlock();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    void rotateBlock();
    void changeToNextBlock();
};