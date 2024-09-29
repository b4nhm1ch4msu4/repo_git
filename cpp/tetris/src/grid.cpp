#include "grid.h"
#include "colors.h"
#include <cmath>
#include <raylib.h>
#include <vector>

Grid::Grid() {
  numCols = 10;
  numRows = 20;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++)
    for (int col = 0; col < numCols; col++) {
      grid[row][col] = 0;
    }
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellVal = grid[row][col];
      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellVal]);
    }
  }
}

bool Grid::IsCellOut(int col, int row) {
  if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(int col, int row) {
  if (grid[row][col] == 0) {
    return true;
  }
  return false;
}

bool Grid::IsRowFull(int row) {
  for (int col = 0; col < numCols; col++) {
    if (grid[row][col] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row) {
  for (int col = 0; col < numCols; col++) {
    grid[row][col] = 0;
  }
}

void Grid::MoveRowDown(int row, int numRows) {
  for (int col = 0; col < numCols; col++) {
    grid[row + numRows][col] = grid[row][col];
    grid[row][col] = 0;
  }
}

int Grid::ClearFullrow() {
  int completed = 0;
  for (int row = numRows - 1; row >= 0; row--) {
    if (IsRowFull(row)) {
      ClearRow(row);
      completed++;
    } else if (completed >= 0) {
      MoveRowDown(row, completed);
    }
  }
  return completed;
}
