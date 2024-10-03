#include <raylib.h>

int main(int argc, char *argv[]) {
  InitWindow(300, 600, "Tetris Classic");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
