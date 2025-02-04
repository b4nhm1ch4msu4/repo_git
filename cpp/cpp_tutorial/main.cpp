#include <iostream>

void print(int num) {
  std::cout << "int function print number: " << num << '\n';
}

void print(double num) {
  std::cout << "int function print double: " << num << '\n';
}

int main() {
  float num = 10999;
  print('c');
  print(num);
}
