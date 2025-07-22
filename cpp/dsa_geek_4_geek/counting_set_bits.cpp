#include <iostream>

/*
Using Bitwise AND with Shift Operator

In this method, we use the bitwise AND operator (&) to check each bit of the number. We process all bits by repeatedly right-shifting the number once after checking whether each one is set.
 */
unsigned int countingSetBits(unsigned int num) {
  unsigned int counter{0};
  while (num) {
    counter += num & 1;
    num = num >> 1;
  }
  return counter;
}



int main (int argc, char *argv[]) {
  unsigned int res{countingSetBits(15)};
  std::cout << res << std::endl;
  return 0;
}
