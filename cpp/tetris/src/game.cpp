#include "game.h"
#include "position.h"
#include <cstdlib>
#include <ctime>
#include <raylib.h>
#include <vector>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  srand(time(0));
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {
  if (!blocks.size()) {
    srand(time(0));
    blocks = GetAllBlocks();
  }
  int randomIndex = rand() % blocks.size();
  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return block;
}

std::vector<Block> Game::GetAllBlocks() {
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
  grid.Draw();
  currentBlock.Draw();
}

void Game::HandlerInput() {
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
  case KEY_LEFT:
    MoveLeft();
    break;
  case KEY_RIGHT:
    MoveRight();
    break;
  case KEY_DOWN:
    MoveDown();
    break;
  case KEY_UP:
    RotateBlock();
    break;
  }
}

void Game::MoveLeft() {
  currentBlock.Move(-1, 0);
  if (IsBlockOut() || !BlockFits()) {
    currentBlock.Move(1, 0);
  }
}

void Game::MoveRight() {
  currentBlock.Move(1, 0);
  if (IsBlockOut() || !BlockFits()) {
    currentBlock.Move(-1, 0);
  }
}
void Game::MoveDown() {
  currentBlock.Move(0, 1);
  if (IsBlockOut() || !BlockFits()) {
    currentBlock.Move(0, -1);
    LockBlock();
  }
}

void Game::RotateBlock() {
  currentBlock.Rotate();
  if (IsBlockOut() || !BlockFits()) {
    currentBlock.UndoRotate();
  }
}

bool Game::IsBlockOut() {
  std::vector<Position> tiles = currentBlock.getCellPositions();
  for (Position item : tiles) {
    if (grid.IsCellOut(item.col, item.row)) {
      return true;
    }
  }
  return false;
}

void Game::LockBlock() {
  std::vector<Position> tiles = currentBlock.getCellPositions();
  for (Position item : tiles) {
    grid.grid[item.row][item.col] = currentBlock.id;
  }
  currentBlock = nextBlock;
  nextBlock = GetRandomBlock();
}

bool Game::BlockFits() {
  std::vector<Position> tiles = currentBlock.getCellPositions();
  for (Position item : tiles) {
    if (!grid.IsCellEmpty(item.col, item.row)) {
      return false;
    }
  }
  return true;
}
