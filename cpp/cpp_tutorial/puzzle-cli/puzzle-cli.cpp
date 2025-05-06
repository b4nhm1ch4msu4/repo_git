#include <iostream>
constexpr int g_consoleLines{25};

class Tile {
  int m_number;

 public:
  Tile(int number) : m_number{number} {}

  bool isEmpty() const { return m_number == 0; }

  int getNum() const { return m_number; }

  friend std::ostream& operator<<(std::ostream& out, const Tile& tile) {
    if (tile.isEmpty()) {
      out << " \t";
    } else {
      out << tile.getNum() << '\t';
    }
    return out;
  }
};

class Board {
  static constexpr int s_size{4};
  Tile m_tiles[s_size][s_size]{Tile{1},  Tile{2},  Tile{3},  Tile{4},  Tile{5},  Tile{6},
                               Tile{7},  Tile{8},  Tile{9},  Tile{10}, Tile{11}, Tile{12},
                               Tile{13}, Tile{14}, Tile{15}, Tile{0}};

 public:
  Board() {}

  friend std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int i{0}; i < g_consoleLines; i++) {
      out << '\n';
    }
    for (int i = 0; i < s_size; i++) {
      for (int j = 0; j < s_size; j++) {
        out << board.m_tiles[i][j];
      }
      out << '\n';
    }
    return out;
  }
};

namespace UserInput {
void getInput() {
  char input{};
  while (true) {
    std::cin >> input;
    if (input == 'w' || input == 's' || input == 'a' || input == 'd') {
      std::cout << "Valid command" << std::endl;
    } else if (input == 'q') {
      std::cout << "\n\nBye!\n\n" << std::endl;
      break;
    }
  }
}
}  // namespace UserInput

//
class Direction {
  enum Type { up, down, left, right, max_directions };

 private:
  int currentDirection{};

 public:
  Direction(Type type) : currentDirection(type) {}

  Direction operator-() const {
    if (currentDirection == Type::up)
      return Direction{Type::down};
    if (currentDirection == Type::down)
      return Direction{Type::up};
    if (currentDirection == Type::left)
      return Direction{Type::right};
    if (currentDirection == Type::right)
      return Direction{Type::left};
    return Direction{Type::max_directions};
  }

  friend std::ostream& operator<<(std::ostream& out, const Direction& direction) {
    switch (direction.currentDirection) {
      case Direction::Type::up:
        out << "up";
        break;
      case Direction::Type::down:
        out << "down";
        break;
      case Direction::Type::left:
        out << "left";
        break;
      case Direction::Type::right:
        out << "right";
        break;
    }
    return out;
  }
};

int main() {
  Board board{};
  std::cout << board;
  UserInput::getInput();
  return 0;
}
