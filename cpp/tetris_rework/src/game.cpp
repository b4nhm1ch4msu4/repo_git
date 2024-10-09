#include "../includes/game.h"
#include <cstdlib>
#include <ctime>
#include <raylib.h>
#include <vector>

Game::Game() {
  // Get random seed
  std::srand(std::time(0));

  isGameOver = false;
  score = 0;
  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  InitAudioDevice();
  music = LoadMusicStream("assets/sounds/music.mp3");
  PlayMusicStream(music);
  rotateSound = LoadSound("assets/sounds/rotate.mp3");
  clearSound = LoadSound("assets/sounds/clear.mp3");
};
Game::~Game() {
  UnloadSound(rotateSound);
  UnloadSound(clearSound);
  UnloadMusicStream(music);
  CloseAudioDevice();
}

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
  currentBlock.Draw(11, 11);
  switch (nextBlock.id) {

  case 2:
    nextBlock.Draw(260, 260);
    break;
  case 1:
    nextBlock.Draw(275, 245);
    break;
  default:
    nextBlock.Draw(290, 260);
    break;
  }
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
    UpdateScore(0, 1);
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
  int rowCleared = grid.ClearFullRow();
  if (rowCleared) {

    PlaySound(clearSound);
    UpdateScore(rowCleared, 0);
  }
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
  score = 0;
  grid.Init();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  PlayMusicStream(music);
}
void Game::UpdateScore(int linesCleared, int moveDownPoints) {
  switch (linesCleared) {
  case 1:
    score += 10;
    break;
  case 2:
    score += 25;
    break;
  case 3:
    score += 40;
    break;
  }

  score += moveDownPoints;
}
