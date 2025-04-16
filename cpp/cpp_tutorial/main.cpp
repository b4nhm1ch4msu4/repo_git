#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <thread>
#include "Timer.h"

bool greater(int a, int b) {
  return (a < b);
}

int main() {
  std::cout << "How many names would you like to enter ? ";
  std::size_t num{};
  std::cin >> num;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::string* name{new std::string[num]{}};
  for (std::size_t i{0}; i < num; i++) {
    std::cout << "Enter name " << i + 1 << ": ";
    std::getline(std::cin, name[i]);
  }

  for (std::size_t i{0}; i < num; i++) {
    std::cout << name[i] << '\n';
  }
}
