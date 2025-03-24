#include <iostream>

int main(int argc, char* argv[]) {
  constexpr int perfect_square[]{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
  while (true) {
    bool found = false;
    std::cout << "Enter a single digit integer, or -1 to quit: ";
    int input;
    std::cin >> input;
    if (input == -1)
      break;
    for (auto i : perfect_square) {
      if (input == i) {
        found = true;
        std::cout << "It's a perfect square\n";
      }
    }
    if (!found) {
      std::cout << "It's not a perfect square\n";
    }
  }
  return 0;
}
