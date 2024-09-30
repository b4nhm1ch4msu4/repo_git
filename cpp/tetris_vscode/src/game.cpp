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
  gameOver = false;
  score = 0;
  InitAudioDevice();
  music = LoadMusicStream("sounds/music.mp3");
  PlayMusicStream(music);
  clearSound = LoadSound("sounds/clear.mp3");
  rotateSound = LoadSound("sounds/rotate.mp3");
}

Game::~Game() {
  UnloadSound(clearSound);
  UnloadSound(rotateSound);
  CloseAudioDevice();
  UnloadMusicStream(music);
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
  currentBlock.Draw(11, 11);
  nextBlock.Draw(270, 270);
}

void Game::HandlerInput() {
  int keyPressed = GetKeyPressed();
  if (gameOver && keyPressed != 0) {
    gameOver = false;
    Reset();
  }
  switch (keyPressed) {
  case KEY_LEFT:
    MoveLeft();
    break;
  case KEY_RIGHT:
    MoveRight();
    break;
  case KEY_DOWN:
    MoveDown();
    UpdateScore(0, 1);
    break;
  case KEY_UP:
    RotateBlock();

    break;
  }
}

void Game::MoveLeft() {
  if (!gameOver) {
    currentBlock.Move(-1, 0);
    if (IsBlockOut() || !BlockFits()) {
      currentBlock.Move(1, 0);
    }
  }
}

void Game::MoveRight() {
  if (!gameOver) {
    currentBlock.Move(1, 0);
    if (IsBlockOut() || !BlockFits()) {
      currentBlock.Move(-1, 0);
    }
  }
}
void Game::MoveDown() {
  if (!gameOver) {
    currentBlock.Move(0, 1);
    if (IsBlockOut() || !BlockFits()) {
      currentBlock.Move(0, -1);
      LockBlock();
    }
  }
}

void Game::RotateBlock() {
  if (!gameOver) {
    currentBlock.Rotate();
    if (IsBlockOut() || !BlockFits()) {
      currentBlock.UndoRotate();
    } else {
      PlaySound(rotateSound);
    }
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
  if (!BlockFits()) {
    gameOver = true;
  }
  nextBlock = GetRandomBlock();
  int rows = grid.ClearFullrow();
  if (rows) {
    PlaySound(clearSound);
  }
  UpdateScore(rows, 0);
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

void Game::Reset() {
  grid.Initialize();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  score = 0;
}

void Game::UpdateScore(int lineCleared, int moveDownPoints) {
  switch (lineCleared) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 200;
    break;
  case 3:
    score += 500;
    break;
  default:
    break;
  }

  score += moveDownPoints;
}
