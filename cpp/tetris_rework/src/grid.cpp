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
      DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1,
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

bool Grid::IsCellOutside(int col, int row) {
  if (0 <= col && col < 10 && 0 <= row && row < 20) {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(int col, int row) {
  if (grid[row][col]) {
    return false;
  }
  return true;
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

void Grid::MoveRowDown(int row, int rowsDown) {
  for (int col = 0; col < numCols; col++) {
    grid[row + rowsDown][col] = grid[row][col];
    grid[row][col] = 0;
  }
}

int Grid::ClearFullRow() {
  int completedRows = 0;
  for (int row = numRows - 1; row >= 0; row--) {
    if (IsRowFull(row)) {
      ClearRow(row);
      completedRows += 1;
    } else if (completedRows > 0) {
      MoveRowDown(row, completedRows);
    }
  }
  return completedRows;
}
