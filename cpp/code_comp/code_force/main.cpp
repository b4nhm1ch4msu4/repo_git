#include <algorithm> // for transform
#include <cctype>    // for tolower
#include <iostream>
#include <string>

int main() {
  int testcases{};
  std::cin >> testcases;
  while (testcases--) {
    int n;
    char ch[100];
    std::cin >> n >> ch;
    int min_num{1};
    int max_num{n};
    int result[100]{};
    for (int j{n - 2}; j >= 0; j--) {
      if (ch[j] == '>') {
        result[j + 1] = max_num;
        --max_num;
      }
      if (ch[j] == '<') {
        result[j + 1] = min_num;
        ++min_num;
      }
    }
    result[0] = min_num;
    for (int j{0}; j < n; j++) {
      std::cout << result[j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
