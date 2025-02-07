#include <iostream>

int main() {
  int bombs{1}; // I can has a bomb

  const long &you{bombs}; // You likes to set bombs off
  --bombs;                // I can disarmed a bomb
  std::cout << bombs << '\n';
  std::cout << you << '\n';

  if (you) // If you can still has a bomb
  {
    std::cout << "Bombs away!  Goodbye, cruel world.\n";
  }

  return 0;
}
