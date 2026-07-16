#include "snekstack.h"
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  snekstack_t *first = stack_new(2);
  printf("count: %zu\n", first->count);
  printf("capacity: %zu\n", first->capacity);
  printf("data: %p\n", first->data);
  for (int i = 0; i < first->count; i++) {
  printf(" ,%zu",first->data[i]);
  }

  int a = 1;
  stack_push(first, &a);
  printf("count: %zu\n", first->count);
  printf("capacity: %zu\n", first->capacity);
  printf("data: %p\n", first->data);
  for (int i = 0; i < first->count; i++) {
  printf(" ,%zu",first->data[i]);
  }
  return 0;
}
