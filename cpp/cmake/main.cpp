#include "includes/hello.h"
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello world" << std::endl;
  hello temp = hello();
  temp.say_hi();
  return 0;
}
