#include <iostream>

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

int main() {
  Tile tile1{10};
  Tile tile2{8};
  Tile tile3{0};  // the missing tile
  Tile tile4{1};

  std::cout << "0123456789ABCDEF\n";  // to make it easy to see how many spaces are in the next line
  std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

  std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
  std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum()
            << '\n';

  return 0;
}
