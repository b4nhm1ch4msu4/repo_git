#include <iostream>
#include "random.h"

int main(int argc, char* argv[]) {
  int start{};
  int quantity{};
  std::cout << "Start where? ";
  std::cin >> start;
  std::cout << "How many? ";
  std::cin >> quantity;
  int multiplier {Random::get(2, 4)};
  std::cout << "I generated " << quantity
            << " square numbers. Do you know what each number is after multiplying it by "
            << multiplier << "?";
  return 0;
}
