#pragma once
#include <raylib.h>
#include <vector>

class Grid {
  int numCols, numRows, cellSize;
  std::vector<Color> colors;
  bool IsRowFull(int);
  void ClearRow(int);
  void MoveRowDown(int, int);

public:
  Grid();
  void Initialize();
  void print();
  int grid[20][10];
  void Draw();
  bool IsCellOut(int col, int row);
  bool IsCellEmpty(int col, int row);
  int ClearFullrow();
};
