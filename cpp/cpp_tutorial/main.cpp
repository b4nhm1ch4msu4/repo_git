#include <iostream>

template <typename T, typename Y> auto sub(T a, Y b) { return a - b; }

int main() {
  std::cout << sub(2, 3) << '\n';
  std::cout << sub(1.2, 3) << '\n';
  std::cout << sub(3, 2) << '\n';
  std::cout << sub(3.5, 2) << '\n';
  std::cout << sub(4, 1.5) << '\n';
}
