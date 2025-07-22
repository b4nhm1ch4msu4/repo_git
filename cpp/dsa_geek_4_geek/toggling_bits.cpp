/*
Toggling a Specific Bit in C++

To toggle a specific bit in a number, we can use a bitmask with the XOR operator. In the bitmask, only the bit that we want to toggle is set to 1, while all other bits are set to 0.
 */

#include <iostream>
unsigned int togglingBits(unsigned int num, unsigned int pos){
  unsigned int mask = 1 << pos;
  return num ^ mask;
}

int main (int argc, char *argv[]) {
  unsigned int num{29};
  unsigned int pos{2};
  unsigned int res{togglingBits(num, pos)};
  std::cout << res << std::endl;
  return 0;
}
