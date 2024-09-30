#include "include/grid.h"
#include "raylib.h"

int main(void) {
  InitWindow(320, 620, "Tetris made by raylib");
  Grid grid = Grid();
  while (!WindowShouldClose()) {
    BeginDrawing();
    grid.Draw();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
