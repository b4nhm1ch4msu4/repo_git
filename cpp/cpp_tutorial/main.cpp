#include <iostream>
int main()
{
  int x{5};           // non-const
  int* const ptr{&x}; // ptr points to a "const int"
  std::cout << *ptr << '\n';

  /**ptr = 6;*/
  x = 6; // allowed: the value is still non-const when accessed through
  std::cout << *ptr << '\n';

  return 0;
}
