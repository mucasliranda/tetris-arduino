#pragma once
#include <vector>
#include "grid/grid.h"
#include "block/block.h"

class Game {
  public:
    Game();
    void handleInput();
    bool gameOver;
    int score;
    void draw();

  private:
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Keyboard keyboard;
};