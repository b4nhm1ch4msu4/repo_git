#include <iostream>
#include <cstring>

void print(const char str[]){
  const char *ptr{str};
  while(*ptr != '\0'){
    ++ptr;
  }
  while (ptr-- != str) {
    std::cout << *ptr;
  }
}

int main(int argc, char* argv[]) {
  char str[]{"hello world"};
  print(str);
  return 0;

}
