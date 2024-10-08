#pragma once
#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  int id;
  void Draw(int, int);
  void Move(int, int);
  int rotateState;
  std::vector<Position> GetCellPos();

protected:
  int cellSize;
  int rowOffset, colOffset;
  std::map<int, std::vector<Position>> cells;
  std::vector<Color> colors;
};
