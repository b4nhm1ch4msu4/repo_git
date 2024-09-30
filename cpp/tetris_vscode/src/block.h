#pragma once
#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
  int rowOffset, colOffset;

public:
  Block();
  int id;
  std::map<int, std::vector<Position>> cells;
  void Draw(int, int);
  void Move(int, int);
  std::vector<Position> getCellPositions();
  void Rotate();
  void UndoRotate();
};
