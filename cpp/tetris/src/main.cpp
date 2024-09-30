#include "colors.h"
#include "game.h"
#include <cstdio>
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

// Entry point
int main() {
  InitWindow(500, 620, "raylib Tetris");
  SetTargetFPS(60);
  Font font = LoadFontEx("font/JetBrainsMonoNerdFont-Medium.ttf", 64, 0, 0);
  Game game = Game();
  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    BeginDrawing();
    ClearBackground(darkBlue);
    DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
    if (game.gameOver) {
      DrawTextEx(font, "Game Over", {320, 450}, 40, 2, WHITE);
    }
    DrawRectangleRounded({330, 55, 170, 60}, 0.3, 6, lightBlue);
    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, {330 + (170 - textSize.x) / 2, 65}, 38, 2,
               WHITE);
    DrawRectangleRounded({330, 215, 170, 180}, 0.3, 6, lightBlue);
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
