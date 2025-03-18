#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

namespace Animal {
enum { chicken, dog, cat, elephant, duck, snake, total };
}

int main(int argc, char *argv[]) {
  std::vector<int> legs{2, 4, 4, 4, 2, 0};
  assert(Animal::total == legs.size());
  std::cout << "elephant has " << legs[Animal::elephant] << " legs\n";
}
