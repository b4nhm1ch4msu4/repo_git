#include <stdio.h>

int i = 9;
int random_func() {
  i++;
  printf("%d\n", i);
  return 0;
}
int main(int argc, char *argv[]) {
  int arr[5] = {0, 1, 2, 3, 4};
  random_func();
  return 0;
}
