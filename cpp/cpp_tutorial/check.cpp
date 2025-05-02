#include <iostream>
int main(int argc, char* argv[]) {
  double x = -123.956;
  int whole_part = static_cast<int>(x);  // Truncates (drops fractional part)
  std::cout << "The whole part of " << x << " is " << whole_part << '\n';
  return 0;
}
