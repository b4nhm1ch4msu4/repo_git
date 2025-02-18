#include <cassert>
#include <cstdio>
#include <iostream>

void printDivision(int x, int y)
{
  assert(y != 0 && "Error: Could not divide by zero");
  std::cout << static_cast<double>(x) / y;
}

int main(int argc, char* argv[]) { return 0; }
