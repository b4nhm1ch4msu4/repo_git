#include <iostream>

void printRef(const int &x) { std::cout << "x :" << x << '\n'; }

int main() {
  int x = 10;
  int &ref{x};
  printRef(x);
  printRef(10);
  int age {100};
  std::cout << age;
  printRef(ref);
  return 0;
}
