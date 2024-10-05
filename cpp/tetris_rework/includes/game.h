#pragma once
#include "../src/blocks.cpp"
#include "grid.h"
#include <vector>

class Game {
public:
  Game();
  Grid grid;

private:
  Block currentBlock, nextBlock;
  Block GetRandomBlock();
  std::vector<Block> blocks;
};
