#include <cmath>
#include <deque>
#include <raylib.h>
#include <raymath.h>

using namespace std;

Color darkGreen = Color{20, 160, 133, 255};
int cellSize = 20;
int cellCount = 25;
int offset = 60;

double inputTimeout = 0;
float lastTimeUpdate = 0;
bool EventTrigged(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastTimeUpdate >= interval) {
    lastTimeUpdate = currentTime;
    return true;
  }
  return false;
}

//----------------
//---Food class---
//----------------
class Food {
public:
  Vector2 position = GetRandomPos();
  Vector2 GetRandomPos() {
    float x = GetRandomValue(2, 25);
    float y = GetRandomValue(2, 25);
    return {x, y};
  }

  void Draw() {
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize,
                  cellSize, RED);
  }
};

//-----------------
//---Snake class---
//-----------------
class Snake {
public:
  Snake() { InitSnake(); }
  deque<Vector2> body;
  Vector2 Direction;
  void InitSnake() {
    body = {Vector2{6, 5}, Vector2{5, 5}, Vector2{4, 5}};
    Direction = {1, 0};
  }
  void Update() {
    body.pop_back();
    body.push_front(Vector2Add(body.front(), Direction));
  }

  void Draw() {
    int size = body.size();
    for (int i = 0; i < size; i++) {
      float x = body[i].x;
      float y = body[i].y;
      Rectangle rec = Rectangle{x * cellSize, y * cellSize, (float)cellSize,
                                (float)cellSize};
      DrawRectangleRounded(rec, 0.5, 6, BLUE);
    }
  };
};

//-----------------
//---Game class---
//-----------------
class Game {
public:
  Sound eatSound, wallSound;
  int score = 0;
  bool isGameOver = false;
  Snake snake = Snake();
  Food food = Food();
  Game() {
    InitAudioDevice();
    eatSound = LoadSound("sounds/eat.mp3");
    wallSound = LoadSound("sounds/wall.mp3");
  }
  ~Game() {
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
  }
  void Draw() {
    DrawRectangleLinesEx(Rectangle{(float)offset - 10, (float)offset - 10,
                                   (float)cellSize * cellCount,
                                   (float)cellSize * cellCount},
                         10, BLACK);
    snake.Draw();
    food.Draw();
  }
  void Update() {
    if (isSnakeInside() && !IsCollisionWithBody()) {
      snake.Update();
      CheckColisionWithFood();
    } else {
      isGameOver = true;
      return;
    }
  }
  void CheckColisionWithFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
      food.position = food.GetRandomPos();
      snake.body.push_front(Vector2Add(snake.body[0], snake.Direction));
      score++;
      PlaySound(eatSound);
    }
  }
  bool IsCollisionWithBody() {
    int size = snake.body.size();
    for (int i = 1; i < size; i++) {
      if (Vector2Equals(snake.body[0], snake.body[i])) {
        return true;
      }
    }
    return false;
  }

  bool isSnakeInside() {
    Vector2 currentPos = snake.body[0];
    if (2 <= currentPos.x && currentPos.x <= 25 && 2 <= currentPos.y &&
        currentPos.y <= 25) {
      return true;
    }
    PlaySound(wallSound);
    return false;
  }
};

//----------------
//--Entry Point---
//----------------
int main() {
  InitWindow(offset * 2 + cellSize * cellCount,
             offset * 2 + cellSize * cellCount, "Snake Game");
  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkGreen);
    game.Draw();
    DrawText("Snake Retro", offset - 5, offset - 50, 40, BLACK);
    DrawText(TextFormat("%i", game.score), offset + 5,
             offset + cellCount * cellSize + 5, 30, BLACK);
    if (game.isGameOver && IsKeyPressed(KEY_SPACE)) {
      game.isGameOver = false;
      game.snake.InitSnake();
      game.score = 0;
    }
    if (EventTrigged(0.2)) {
      game.Update();
    }

    // Handle input
    if (GetTime() - inputTimeout > 0.2) {
      int keyPressed = GetKeyPressed();
      switch (keyPressed) {
      case KEY_RIGHT:
        if (game.snake.Direction.x != -1) {
          game.snake.Direction = {1, 0};
          inputTimeout = GetTime();
        }
        break;
      case KEY_UP:
        if (game.snake.Direction.y != 1) {
          game.snake.Direction = {0, -1};
          inputTimeout = GetTime();
        }
        break;
      case KEY_LEFT:
        if (game.snake.Direction.x != 1) {
          game.snake.Direction = {-1, 0};
          inputTimeout = GetTime();
        }
        break;
      case KEY_DOWN:
        if (game.snake.Direction.y != -1) {
          game.snake.Direction = {0, 1};
          inputTimeout = GetTime();
        }
        break;
      }
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
