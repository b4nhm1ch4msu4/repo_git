#include "snekstack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_free(snekstack_t *stack) {
  if (stack == NULL) {
    return;
  }
  free(stack->data);
  free(stack);
}
void *stack_pop(snekstack_t *stack) {
  // ?
  if (stack->count == 0) {
    return NULL;
  }
  stack->count--;
  return stack->data[stack->count];
}
void stack_push(snekstack_t *stack, void *obj) {
  // ?
  if (stack->count == stack->capacity) {

    size_t new_cap = stack->capacity * 2;
    void **new_data = realloc(stack->data, sizeof(void *) * new_cap);
    if (new_data == NULL) {
      return;
    }
    stack->capacity = new_cap;
    stack->data = new_data;
  }
  stack->data[stack->count] = obj;
  stack->count += 1;
}

// don't touch below this line

snekstack_t *stack_new(size_t capacity) {
  snekstack_t *stack = malloc(sizeof(snekstack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}
