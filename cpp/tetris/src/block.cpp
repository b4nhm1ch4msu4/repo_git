#include "block.h"
#include "colors.h"
#include "position.h"
#include <raylib.h>
#include <vector>

Block::Block() {
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
  rowOffset = 0;
  colOffset = 0;
}

void Block::Draw() {
  std::vector<Position> tiles = getCellPositions();
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize, item.row * cellSize, cellSize - 1,
                  cellSize - 1, colors[id]);
  }
}

void Block::Move(int col, int row) {
  rowOffset += row;
  colOffset += col;
}

std::vector<Position> Block::getCellPositions() {
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;
  for (Position item : tiles) {
    Position newPos = Position(item.row + rowOffset, item.col + colOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

void Block::Rotate() { rotationState = (rotationState + 1) % 4; }
void Block::UndoRotate() { rotationState = (rotationState + 3) % 4; }
