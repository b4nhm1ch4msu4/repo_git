#include "includes/colors.h"
#include "includes/grid.h"
#include "src/blocks.cpp"
#include <raylib.h>

int main(int argc, char *argv[]) {
  InitWindow(320, 620, "Tetris Classic");
  SetTargetFPS(60);
  Grid grid = Grid();
  IBlock block = IBlock();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(LightGray);
    grid.Draw();
    block.Draw();

    // int keyPressed = GetKeyPressed();
    // switch (keyPressed) {
    // case KEY_DOWN:
    //   block.MoveDown();
    //   break;
    //
    // case KEY_UP:
    //   block.Rotate();
    //   break;
    //
    // case KEY_LEFT:
    //   block.MoveLeft();
    //   break;
    //
    // case KEY_RIGHT:
    //   block.MoveRight();
    //   break;
    // }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
