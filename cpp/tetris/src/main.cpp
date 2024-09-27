#include "grid.h"
#include <raylib.h>

int main() {
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(300, 800, "raylib Tetris");
  SetTargetFPS(60);

  Grid grid = Grid();
  grid.grid[0][0] = 1;
  grid.grid[1][3] = 2;
  grid.grid[3][5] = 5;
  grid.grid[6][9] = 7;
  grid.print();
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);
    grid.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
