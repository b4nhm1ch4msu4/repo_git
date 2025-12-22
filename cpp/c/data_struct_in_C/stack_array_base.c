#include <stdio.h>
#include <stdlib.h>

// Array-based

#define STACK_CAPACITY 10

typedef struct Stack {
  int size;
  int cap;
  int *arr_ptr;
} Stack;

Stack *stack_init(int val);
void push(Stack *my_stack, int val);
int pop(Stack *my_stack);
void stack_print(Stack *my_stack);

Stack *stack_init(int val) {
  int *container = (int *)calloc(STACK_CAPACITY, sizeof(int));
  container[0] = val;
  Stack *my_stack = (Stack *)malloc(sizeof(Stack));
  my_stack->cap = 10;
  my_stack->size = 1;
  my_stack->arr_ptr = container;
  return my_stack;
}

void push(Stack *my_stack, int val) {
  my_stack->arr_ptr[my_stack->size] = val;
  my_stack->size++;
}

int pop(Stack *my_stack) {
  int pop_val = my_stack->arr_ptr[my_stack->size - 1];
  my_stack->arr_ptr[my_stack->size - 1] = 0;
  my_stack->size--;
  return pop_val;
}

void stack_print(Stack *my_stack) {
  printf("Array: ");
  for (int i = 0; i < STACK_CAPACITY; i++) {
    printf("%d ", my_stack->arr_ptr[i]);
  }
  printf("\n");
  printf("Size: %d\n", my_stack->size);
  printf("Capacity: %d\n", my_stack->cap);
}

/////////////////////////////
///// MAIN ENTRY POINT /////
////////////////////////////
int main(int argc, char *argv[]) {
  Stack *my_stack_ptr = stack_init(1);
  stack_print(my_stack_ptr);
  push(my_stack_ptr, 2);
  push(my_stack_ptr, 3);
  push(my_stack_ptr, 4);
  push(my_stack_ptr, 5);
  stack_print(my_stack_ptr);
  pop(my_stack_ptr);
  pop(my_stack_ptr);
  stack_print(my_stack_ptr);

  pop(my_stack_ptr);
  pop(my_stack_ptr);
  stack_print(my_stack_ptr);
  return 0;
}
