#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> v(3);
  for (int i = 0; i < v.size(); i++) {
    std::cin >> v[i];
  }
  std::cout << v[0] + v[1] + v[2] << '\n';
  std::cout << v[0] * v[1] * v[2] << '\n';
  return 0;
}
