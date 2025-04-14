#include <iostream>

int main(int argc, char *argv[]) {
  std::string input{};
  std::cin >> input;
  std::size_t input_size = input.size();
  std::size_t i = 0;
  while (i < input_size) {
    char cur = input[i];
    bool found = true;
    int j = 1;
    while ( j < 7) {
      if (input[i + j] != cur) {
        found = false;
        break;
      }
      ++j;
    }
    if (found) {
      std::cout << "yes\n";
      return 0;
    }
    i = i + j;
  }
  std::cout << "no\n";
  return 0;
}
