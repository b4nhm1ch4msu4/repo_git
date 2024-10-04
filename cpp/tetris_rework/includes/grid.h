#pragma once
#include "colors.h"
#include <raylib.h>
#include <vector>

class Grid {
public:
  Grid();
  void Draw();
  void Init();

private:
  int numCols, numRows, cellSize;
  int grid[20][10];
  std::vector<Color> colors;
};
