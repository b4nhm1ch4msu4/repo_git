#include "game.h"
#include <raylib.h>

double lastUpdateTime = 0;
bool EventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}
int main() {
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(300, 800, "raylib Tetris");
  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);
    game.Draw();
    game.HandlerInput();
    if (EventTriggered(0.2)) {
      game.MoveDown();
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
