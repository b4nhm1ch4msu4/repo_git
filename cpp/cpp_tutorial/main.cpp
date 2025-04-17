#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <thread>
#include "Timer.h"

std::size_t Name_num() {
  std::cout << "How many names would you like to enter ? ";
  std::size_t num{};
  std::cin >> num;
  return num;
}

int main() {
  // std::cin.clear();
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::size_t num = Name_num();
  std::string* names{new std::string[num]};
  for (std::size_t i{0}; i < num; i++) {
    std::cout << "Enter name " << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
  }

  std::sort(names, names + num, std::greater<>{});

  for (std::size_t i{0}; i < num; i++) {
    std::cout << names[i] << '\n';
  }
  delete[] names;
  names = nullptr;
}
