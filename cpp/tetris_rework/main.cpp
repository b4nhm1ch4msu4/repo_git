#include "includes/colors.h"
#include "includes/grid.h"
#include <raylib.h>

int main(int argc, char *argv[]) {
  InitWindow(300, 600, "Tetris Classic");
  SetTargetFPS(60);
  Grid grid = Grid();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(LightGray);
    grid.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
