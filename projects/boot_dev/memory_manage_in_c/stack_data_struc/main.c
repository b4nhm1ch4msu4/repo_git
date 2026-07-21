#include "snekstack.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  snekstack_t *first = stack_new(2);
  printf("count: %zu\n", first->count);
  printf("capacity: %zu\n", first->capacity);
  printf("data: %p\n", first->data);
  for (int i = 0; i < first->count; i++) {
    printf(" ,%d", *(int *)(first->data[i]));
  }

  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;
  stack_push(first, &a);
  stack_push(first, &b);
  stack_push(first, &c);
  stack_push(first, &d);
  stack_push(first, &e);
  printf("count: %zu\n", first->count);
  printf("capacity: %zu\n", first->capacity);
  printf("data: %p\n", first->data);
  for (int i = 0; i < first->count; i++) {
    printf(" ,%d", *(int *)(first->data[i]));
  }

  printf("\n");
  printf("Pop\n");
  stack_pop(first);
  for (int i = 0; i < first->count; i++) {
    printf(" ,%d", *(int *)(first->data[i]));
  }
  printf("\n");
  stack_pop(first);
  stack_pop(first);
  stack_pop(first);
  for (int i = 0; i < first->count; i++) {
    printf(" ,%d", *(int *)(first->data[i]));
  }
  return 0;
}
