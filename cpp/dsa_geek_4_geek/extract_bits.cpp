#include <iostream>

/*
To extract k bits from a given position pos in a number, first perform right shift on num by pos bits that brings the target bits to the least significant positions, then create a mask with k bits set to 1 and apply it to shifted number (that we got after performing right shift operation) using the AND operation.
*/
unsigned int extractBits(unsigned int num, unsigned int k, unsigned int pos) {
  unsigned int shifted = num >> pos;
  unsigned int mask = (1 << k) - 1;
  return shifted & mask;
}

int main(int argc, char *argv[]) {
  unsigned int num = 214;
  unsigned int k = 3;
  unsigned int pos = 1;
  unsigned int res = extractBits(num, k, pos);
  std::cout << "Extracted bits: " << res << std::endl;
  return 0;
}
