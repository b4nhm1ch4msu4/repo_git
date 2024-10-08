#pragma once
#include "../src/blocks.cpp"
#include "grid.h"
#include <raylib.h>
#include <vector>

class Game {
public:
  Game();
  ~Game();
  int score;
  bool isGameOver;
  Grid grid;
  void Draw();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  void RotateBlock();
  void HandleInput();
  Music music;

private:
  Block currentBlock, nextBlock;
  Block GetRandomBlock();
  std::vector<Block> blocks;
  std::vector<Block> GetAllBlocks();
  bool IsBlockOutside();
  void LockBlock();
  bool BlockFit();
  void Reset();
  Sound rotateSound;
  Sound clearSound;
  void UpdateScore(int, int);
};
