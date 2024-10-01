#include <cmath>
#include <deque>
#include <raylib.h>
#include <raymath.h>

using namespace std;

Color darkGreen = Color{20, 160, 133, 255};
int cellSize = 20;
int cellCount = 25;
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
  Vector2 position = GetRandomPos();
  Vector2 GetRandomPos() {
    float x = GetRandomValue(0, 24);
    float y = GetRandomValue(0, 24);
    return {x, y};
  }

public:
  void Draw() {
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize,
                  cellSize, RED);
  }
};

//-----------------
//---Snake class---
//-----------------
class Snake {
  deque<Vector2> body = {Vector2{6, 5}, Vector2{5, 5}, Vector2{4, 5}};
  bool isSnakeInside() {
    Vector2 currentPos = body[0];
    if (0 <= currentPos.x && currentPos.x <= 25 && 0 <= currentPos.y &&
        currentPos.y <= 25) {
      return true;
    }
    return false;
  }

public:
  Vector2 Direction = {1, 0};
  // Vector2 GetDirection() { return Vector2Subtract(body[0], body[1]); }
  // void TurnLeft() {
  //   if (Vector2Equals(GetDirection(), {0, -1})) {
  //     body[0] = Vector2Add(body[0], {-1, 1});
  //   }
  //   if (Vector2Equals(GetDirection(), {0, 1})) {
  //     body[0] = Vector2Add(body[0], {-1, -1});
  //   }
  // }
  // void TurnRight() {
  //   if (Vector2Equals(GetDirection(), {0, -1})) {
  //     body[0] = Vector2Add(body[0], {1, 1});
  //   }
  //   if (Vector2Equals(GetDirection(), {0, 1})) {
  //     body[0] = Vector2Add(body[0], {1, -1});
  //   }
  // }
  // void TurnUp() {
  //
  //   if (Vector2Equals(GetDirection(), {1, 0})) {
  //     body[0] = Vector2Add(body[0], {-1, -1});
  //   }
  //   if (Vector2Equals(GetDirection(), {-1, 0})) {
  //     body[0] = Vector2Add(body[0], {1, -1});
  //   }
  // }
  // void TurnDown() {
  //   if (Vector2Equals(GetDirection(), {1, 0})) {
  //     body[0] = Vector2Add(body[0], {-1, 1});
  //   }
  //   if (Vector2Equals(GetDirection(), {-1, 0})) {
  //     body[0] = Vector2Add(body[0], {1, 1});
  //   }
  // }

  void Update() {
    if (isSnakeInside()) {
      body.pop_back();
      body.push_front(Vector2Add(body.front(), Direction));
    }
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
  Snake snake = Snake();
  Food food = Food();
  void Draw() {
    snake.Draw();
    food.Draw();
  }
  void Update() { snake.Update(); }
};

//----------------
//--Entry Point---
//----------------
int main() {
  InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake Game");
  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkGreen);
    game.Draw();
    if (EventTrigged(0.5)) {
      game.Update();
    }

    // Handle input
    int keyPressed = GetKeyPressed();
    switch (keyPressed) {
    case KEY_RIGHT:
      if (game.snake.Direction.x != -1) {
        game.snake.Direction = {1, 0};
      }
      break;
    case KEY_UP:
      if (game.snake.Direction.y != 1) {
        game.snake.Direction = {0, -1};
      }
      break;
    case KEY_LEFT:
      if (game.snake.Direction.x != 1) {
        game.snake.Direction = {-1, 0};
      }
      break;
    case KEY_DOWN:
      if (game.snake.Direction.y != -1) {
        game.snake.Direction = {0, 1};
      }
      break;
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
