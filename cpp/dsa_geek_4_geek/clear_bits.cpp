/* Clearing a Specific Bit in C++
To clear a specific bit in a number, we can create a bitmask with the bit to be cleared set to 0, and all other bits set to 1. We then use the AND operator to clear the bit.
 */
#include <iostream>
unsigned int clearBits(unsigned int num, unsigned int pos) {
  unsigned int shifted = 1 << pos;
  unsigned int mask = ~shifted;
  return num & mask;
}

int main(int argc, char *argv[]) {
  unsigned int res = clearBits(29, 2);
  std::cout << res << std::endl;
  return 0;
}

// to clear multiple bits, use |(OR) to combine shifted, then use not to create mask. 
