#pragma once
#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  void Draw();
  void Rotate();
  void MoveDown();
  void MoveUp();
  void MoveRight();
  void MoveLeft();

protected:
  int id;
  int rotateState;
  int cellSize;
  int rowOffset, colOffset;
  std::map<int, std::vector<Position>> cells;
  std::vector<Color> colors;
  void Move(int, int);
  std::vector<Position> GetCellPos();
};
