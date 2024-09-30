#include "../include/grid.h"
#include <raylib.h>

Grid::Grid() {
  numRows = 20;
  numColumns = 10;
  cellSize = 30;

  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numColumns; col++) {
      grid[row][col] = 0;
    }
  }
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numColumns; col++) {
      DrawRectangle(col * cellSize + 10, row * cellSize + 10, cellSize - 1,
                    cellSize - 1, BLACK);
    }
  }
}
