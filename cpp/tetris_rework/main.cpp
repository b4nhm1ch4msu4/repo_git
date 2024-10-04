#include "includes/colors.h"
#include "includes/grid.h"
#include <raylib.h>

int main(int argc, char *argv[]) {
  InitWindow(350, 650, "Tetris Classic");
  SetTargetFPS(60);
  Grid grid = Grid();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DardGray);
    grid.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
