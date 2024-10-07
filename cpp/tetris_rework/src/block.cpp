#include "../includes/block.h"
#include <raylib.h>
#include <raymath.h>
#include <vector>

Block::Block() {
  rotateState = 0;
  cellSize = 30;
  colOffset = rowOffset = 0;
  colors = GetAllColors();
}
void Block::Draw() {
  std::vector<Position> tiles = GetCellPos();
  for (Position pos : tiles) {
    DrawRectangle(pos.col * cellSize + 11, pos.row * cellSize + 11,
                  cellSize - 1, cellSize - 1, colors[id]);
  }
}
void Block::Move(int col, int row) {
  rowOffset += row;
  colOffset += col;
}
std::vector<Position> Block::GetCellPos() {
  std::vector<Position> tiles = cells[rotateState];
  std::vector<Position> movedTiles;
  for (Position item : tiles) {
    Position movedPos = Position(item.col + colOffset, item.row + rowOffset);
    movedTiles.push_back(movedPos);
  }
  return movedTiles;
}
