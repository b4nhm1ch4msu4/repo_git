#pragma once
#include "colors.h"
#include <raylib.h>
#include <vector>

class Grid {
public:
  Grid();
  void Draw();
  void Init();
  int grid[20][10];

private:
  int numCols, numRows, cellSize;
  std::vector<Color> colors;
};
