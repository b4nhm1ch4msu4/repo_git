#pragma once
#include "block.h"
#include "blocks.cpp"
#include "grid.h"
#include <raylib.h>
#include <vector>

class Game {
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  Block GetRandomBlock();
  void Reset();
  void UpdateScore(int, int);
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  void MoveLeft();
  void MoveRight();
  bool IsBlockOut();
  std::vector<Block> GetAllBlocks();
  Sound rotateSound;
  Sound clearSound;

public:
  Game();
  ~Game();
  bool gameOver;
  int score;
  Grid grid;
  void Draw();
  void HandlerInput();
  void MoveDown();
  Music music;
};
