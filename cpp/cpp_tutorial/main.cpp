#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T> &arr) {
  for (std::size_t i = 0; i < arr.size(); ++i)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
  printArray(arr);
  return 0;
}
