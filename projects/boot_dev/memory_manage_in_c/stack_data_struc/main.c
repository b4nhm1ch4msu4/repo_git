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

  // snek_object_t *obj = new_snek_array(2);
  // snek_object_t *first = new_snek_string("First");
  // snek_object_t *second = new_snek_integer(3);
  // snek_array_set(obj, 0, first);
  // snek_array_set(obj, 1, second);
  // printf("first: %s", obj->data.v_array.elements[0]->data.v_string);
  // printf("second: %d", snek_array_get(obj, 1)->data.v_int);

  // snek_object_t *one = new_snek_integer(1);
  // printf("one data: %d\n",one->data.v_int);
  // snek_object_t *three = new_snek_integer(3);
  // printf("three data: %d\n",three->data.v_int);
  // snek_object_t *four = snek_add(one, three);
  // printf("four data: %d\n",four->data.v_int);
  //
  // printf("kind: %d\n",four->kind);
  // printf("data: %d\n",four->data.v_int);

  // snek_object_t *one = new_snek_float(1.5);
  // printf("one data: %f\n",one->data.v_float);
  // snek_object_t *three = new_snek_float(3.5);
  // printf("three data: %f\n",three->data.v_float);
  // snek_object_t *five = snek_add(one, three);
  // printf("five data: %f\n",five->data.v_float);

  // snek_object_t *hello = new_snek_string("hello");
  // printf("%s\n",hello->data.v_string);
  // snek_object_t *world = new_snek_string(", world");
  // printf("%s\n",world->data.v_string);
  // snek_object_t *greeting = snek_add(hello, world);
  // printf("%s\n",greeting->data.v_string);

  // snek_object_t *one = new_snek_float(1.0);
  // snek_object_t *two = new_snek_float(2.0);
  // snek_object_t *three = new_snek_float(3.0);
  // snek_object_t *four = new_snek_float(4.0);
  // snek_object_t *five = new_snek_float(5.0);
  // snek_object_t *six = new_snek_float(6.0);
  //
  // snek_object_t *v1 = new_snek_vector3(one, two, three);
  // snek_object_t *v2 = new_snek_vector3(four, five, six);
  // snek_object_t *result = snek_add(v1, v2);
  //
  // printf("result {%f, %f, %f}", result->data.v_vector3.x->data.v_float,
  //        result->data.v_vector3.y->data.v_float,
  //        result->data.v_vector3.z->data.v_float);

  // snek_object_t *one = new_snek_integer(1);
  // snek_object_t *ones = new_snek_array(2);
  // snek_array_set(ones, 0, one);
  // snek_array_set(ones, 1, one);
  // printf("first elem of ones obj: %d\n",
  //        ones->data.v_array.elements[0]->data.v_int);
  //
  // snek_object_t *hi = new_snek_string("hi");
  // snek_object_t *hellos = new_snek_array(3);
  // snek_array_set(hellos, 0, hi);
  // snek_array_set(hellos, 1, hi);
  // snek_array_set(hellos, 2, hi);
  // printf("first elem of hellos obj: %s\n",
  //        hellos->data.v_array.elements[0]->data.v_string);
  // snek_object_t *result = snek_add(ones, hellos);
  // printf("first elem of result obj: %d\n",
  //        result->data.v_array.elements[0]->data.v_int);
  //
  // printf("kind: %d\n", result->kind);
  // printf("size: %zu\n", result->data.v_array.size);
  //
  // snek_object_t *first = snek_array_get(result, 0);
  // printf("first should be 1: %d\n", first->data.v_int);
  // snek_object_t *second = snek_array_get(result, 1);
  // printf("second should be 1: %d\n", second->data.v_int);
  // snek_object_t *third = snek_array_get(result, 2);
  // printf("third should be string 'hi': %s\n", third->data.v_string);
  // snek_object_t *fourth = snek_array_get(result, 3);
  // printf("fourth should be string 'hi': %s\n", fourth->data.v_string);
  // snek_object_t *fifth = snek_array_get(result, 4);
  // printf("fifth should be string 'hi': %s\n", fifth->data.v_string);

  snek_object_t *empty = new_snek_array(0);
  snek_object_t *hi = new_snek_string("hi");
  snek_object_t *hellos = new_snek_array(2);
  snek_array_set(hellos, 0, hi);
  snek_array_set(hellos, 1, hi);

  snek_object_t *result = snek_add(empty, hellos);

  printf("result kind: %d\n", result->kind);
  printf("result size: %zu\n", result->data.v_array.size);
  // assert_size(result->data.v_array.size, ==, 2,
  // "result should have 2 elements");

  snek_object_t *first = snek_array_get(result, 0);
  printf("first obj data should be 'hi' : %s\n", first->data.v_string);
  // assert_string_equal(first->data.v_string, "hi", "first == hi");

  snek_object_t *second = snek_array_get(result, 1);
  // assert_string_equal(second->data.v_string, "hi", "second == hi");
  printf("second obj data should be 'hi' : %s\n", second->data.v_string);
}
