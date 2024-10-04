#include "../includes/grid.h"
#include "../includes/colors.h"
#include <raylib.h>

Grid::Grid() {
  numCols = 10;
  numRows = 20;
  cellSize = 30;
  Init();
  colors = GetAllColors();
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellValue = grid[row][col];
      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

void Grid::Init() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      grid[row][col] = 0;
    }
  }
}
