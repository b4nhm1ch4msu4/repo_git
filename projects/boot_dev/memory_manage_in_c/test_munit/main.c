#include "munit/munit.h"

void equal_function(int a, int b) { munit_assert_int(a, ==, b); }
int main(int argc, char *argv[]) {
  equal_function(6, 5);
  return EXIT_SUCCESS;
}
