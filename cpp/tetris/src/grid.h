#pragma once
#include <raylib.h>
#include <vector>

class Grid {
  int numCols, numRows, cellSize;
  std::vector<Color> colors;
  std::vector<Color> GetCellColors();

public:
  Grid();
  void Initialize();
  void print();
  int grid[20][10];
  void Draw();
};
