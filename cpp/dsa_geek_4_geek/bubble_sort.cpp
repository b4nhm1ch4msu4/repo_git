#include <iostream>
#include <utility>
#include <vector>

void bubble_sort(std::vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        std::swap(v[j], v[j + 1]);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> v{2, 5, 4, 3, 10, 20, 15, 8, 1};
  std::cout << "before sorted: ";
  for (int item : v) {
    std::cout << item << ' ';
  }
  std::cout << std::endl;
  bubble_sort(v);

  std::cout << "after sorted: ";
  for (int item : v) {
    std::cout << item << ' ';
  }
  return 0;
}
