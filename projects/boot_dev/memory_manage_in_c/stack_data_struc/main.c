#include "snekobject.h"
#include "snekstack.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // snekstack_t *first = stack_new(2);
  // printf("count: %zu\n", first->count);
  // printf("capacity: %zu\n", first->capacity);
  // printf("data: %p\n", first->data);
  // for (int i = 0; i < first->count; i++) {
  //   printf(" ,%d", *(int *)(first->data[i]));
  // }
  //
  // int a = 1;
  // int b = 2;
  // int c = 3;
  // int d = 4;
  // int e = 5;
  // stack_push(first, &a);
  // stack_push(first, &b);
  // stack_push(first, &c);
  // stack_push(first, &d);
  // stack_push(first, &e);
  // printf("count: %zu\n", first->count);
  // printf("capacity: %zu\n", first->capacity);
  // printf("data: %p\n", first->data);
  // for (int i = 0; i < first->count; i++) {
  //   printf(" ,%d", *(int *)(first->data[i]));
  // }
  //
  // printf("\n");
  // printf("Pop\n");
  // stack_pop(first);
  // for (int i = 0; i < first->count; i++) {
  //   printf(" ,%d", *(int *)(first->data[i]));
  // }
  // printf("\n");
  // stack_pop(first);
  // stack_pop(first);
  // stack_pop(first);
  // for (int i = 0; i < first->count; i++) {
  //   printf(" ,%d", *(int *)(first->data[i]));
  // }
  // return 0;

  // snek_object_t *obj = new_snek_array(2);
  // printf("kind: %d\n", obj->kind);
  // printf("size: %d\n", obj->data.v_array.size);
  // if (obj->data.v_array.elements[0] == NULL) {
  //   printf("Should use calloc");
  // } else {
  //   printf("fail: don't use calloc");
  // }

  snek_object_t *obj = new_snek_array(2);
  snek_object_t *first = new_snek_string("First");
  snek_object_t *second = new_snek_integer(3);
  snek_array_set(obj, 0, first);
  snek_array_set(obj, 1, second);
  printf("first: %s", obj->data.v_array.elements[0]->data.v_string);
  printf("second: %d", snek_array_get(obj, 1)->data.v_int);
}
