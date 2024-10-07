#include "../includes/game.h"
#include <cstdlib>
#include <ctime>
#include <raylib.h>
#include <vector>

Game::Game() {
  // Get random seed
  std::srand(std::time(0));

  isGameOver = false;
  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
};

Block Game::GetRandomBlock() {
  if (blocks.empty()) {
    blocks = GetAllBlocks();
  }
  int randomIdx = std::rand() % blocks.size();
  Block block = blocks[randomIdx];
  blocks.erase(blocks.begin() + randomIdx);
  return block;
}

void Game::Draw() {
  grid.Draw();
  currentBlock.Draw();
}

std::vector<Block> Game::GetAllBlocks() {
  return {IBlock(), LBlock(), ZBlock(), OBlock(), SBlock(), JBlock(), TBlock()};
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();
  if (isGameOver && keyPressed) {
    Reset();
  }
  switch (keyPressed) {
  case KEY_UP:
    RotateBlock();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    break;
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  }
}

void Game::MoveBlockRight() {
  if (!isGameOver) {
    currentBlock.Move(1, 0);
    if (IsBlockOutside() || !BlockFit()) {
      currentBlock.Move(-1, 0);
    }
  }
}
void Game::MoveBlockLeft() {
  if (!isGameOver) {
    currentBlock.Move(-1, 0);
    if (IsBlockOutside() || !BlockFit()) {
      currentBlock.Move(1, 0);
    }
  }
}
void Game::MoveBlockDown() {
  if (!isGameOver) {
    currentBlock.Move(0, 1);
    if (IsBlockOutside() || !BlockFit()) {
      currentBlock.Move(0, -1);
      LockBlock();
    }
  }
}
void Game::RotateBlock() {
  if (!isGameOver) {
    currentBlock.rotateState = (currentBlock.rotateState + 1) % 4;
    if (IsBlockOutside() || !BlockFit()) {
      currentBlock.rotateState = (currentBlock.rotateState + 3) % 4;
    }
  }
}
bool Game::IsBlockOutside() {
  std::vector<Position> tiles = currentBlock.GetCellPos();
  for (Position item : tiles) {
    if (grid.IsCellOutside(item.col, item.row)) {
      return true;
    }
  }
  return false;
}
void Game::LockBlock() {
  std::vector<Position> tiles = currentBlock.GetCellPos();
  for (Position item : tiles) {
    grid.grid[item.row][item.col] = currentBlock.id;
  }
  grid.ClearFullRow();
  currentBlock = nextBlock;
  if (BlockFit() == false) {
    isGameOver = true;
  }
  nextBlock = GetRandomBlock();
}
bool Game::BlockFit() {
  std::vector<Position> tiles = currentBlock.GetCellPos();
  for (Position item : tiles) {
    if (!grid.IsCellEmpty(item.col, item.row)) {
      return false;
    }
  }
  return true;
}
void Game::Reset() {
  isGameOver = false;
  grid.Init();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}
