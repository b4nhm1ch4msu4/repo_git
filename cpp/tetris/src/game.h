#pragma once
#include "block.h"
#include "blocks.cpp"
#include "grid.h"
#include <vector>

class Game {
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  bool IsBlockOut();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();

public:
  Game();
  Grid grid;
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Draw();
  void HandlerInput();
  void MoveLeft();
  void MoveRight();
  void MoveDown();
};
