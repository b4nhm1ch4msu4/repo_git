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
  bool IsCellOutside(int, int);
  bool IsCellEmpty(int, int);
  int ClearFullRow();

private:
  int numCols, numRows, cellSize;
  std::vector<Color> colors;
  bool IsRowFull(int);
  void ClearRow(int);
  void MoveRowDown(int, int);
};
