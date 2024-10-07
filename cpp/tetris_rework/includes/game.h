#pragma once
#include "../src/blocks.cpp"
#include "grid.h"
#include <vector>

class Game {
public:
  Game();
  Grid grid;
  void Draw();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  void RotateBlock();
  void HandleInput();

private:
  bool isGameOver;
  Block currentBlock, nextBlock;
  Block GetRandomBlock();
  std::vector<Block> blocks;
  std::vector<Block> GetAllBlocks();
  bool IsBlockOutside();
  void LockBlock();
  bool BlockFit();
  void Reset();
};
