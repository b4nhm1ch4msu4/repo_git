/* Setting a Specific Bit in C++
To set a specific bit in a number, we use a bitmask and the bitwise OR operator. The bitmask has a 1 at the position of the bit we want to set and 0s elsewhere.
*/

#include <iostream>

unsigned int settingBits(unsigned int num, unsigned int pos){
  unsigned int mask = 1 << pos;
  return num | mask;
}

int main (int argc, char *argv[]) {
  unsigned int num = 103;
  unsigned int pos = 4;
  unsigned int res = settingBits(num, pos);
  std::cout << "Setting bits: " << res << std::endl;
  return 0;
}

// with multiple bits set, use |(OR) to combine masks
