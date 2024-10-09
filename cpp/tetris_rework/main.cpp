#include "includes/colors.h"
#include "includes/game.h"
#include <cstdio>
#include <ctime>
#include <raylib.h>

double lastUpdatedTime = 0;

bool EvenTrigger(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdatedTime >= interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  InitWindow(500, 620, "Tetris Classic");
  SetTargetFPS(60);
  Game game = Game();
  Font font = LoadFontEx("assets/fonts/font.ttf", 64, 0, 0);

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    game.HandleInput();
    if (EvenTrigger(0.2)) {
      game.MoveBlockDown();
    }
    BeginDrawing();
    ClearBackground(LightGray);
    DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", {370, 165}, 38, 2, WHITE);
    if (game.isGameOver) {
      DrawTextEx(font, "GAME\n\nOVER", {375, 450}, 35, 2, RED);
      StopMusicStream(game.music);
    }
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, DarkGray);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, DarkGray);

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

    DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2,
               WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, DarkGray);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
