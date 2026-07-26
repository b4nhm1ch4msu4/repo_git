#include "stdio.h"
#include "stdlib.h"

void swap_ints(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
  // free(c);
}

void swap_strings(char **a, char **b) {
  char *c = *a;
  *a = *b;
  *b = c;
}

int main() {
  int x = 10;
  int y = 20;
  int *a = &x;
  int *b = &y;

  char z = 'a';
  char t = 'b';
  char *c = &z;
  char *d = &t;
  char **e = &c;
  char **f = &d;
  printf("before swap\n");
  printf("value of e: %c\n",**e);
  printf("value of f: %c\n",**f);
  swap_strings(e, f);
  printf("after swap\n");
  printf("value of e: %c\n",**e);
  printf("value of f: %c\n",**f);


  swap_ints(a, b);

  // printf("a value: %d\n", *a);
  // printf("b value: %d\n", *b);
}
