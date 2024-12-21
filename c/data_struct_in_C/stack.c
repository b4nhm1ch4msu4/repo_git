#include <stdio.h>
#include <stdlib.h>

// Linked_List-based

/*typedef struct Node {*/
/*  int val;*/
/*  struct Node *next;*/
/*} Node;*/
/**/
/*typedef struct Stack {*/
/*  Node *head;*/
/*  int size;*/
/*} Stack;*/
/**/
/*Stack *newStack(int val);*/
/*int peek(Stack *my_stack);*/
/*Node *pop(Stack *my_stack);*/
/*void push(Stack *my_stack, int val);*/
/*void stack_print(Stack *my_stack);*/
/**/
/*Stack *newStack(int val) {*/
/*  Node *head_node = (Node *)malloc(sizeof(Node));*/
/*  head_node->val = val;*/
/*  head_node->next = NULL;*/
/**/
/*  Stack *new_stack = (Stack *)malloc(sizeof(Stack));*/
/*  new_stack->head = head_node;*/
/*  new_stack->size = 1;*/
/*  return new_stack;*/
/*}*/
/**/
/*int peek(Stack *my_stack) { return my_stack->head->val; }*/
/**/
/*Node *pop(Stack *my_stack) {*/
/*  Node *del_node = my_stack->head;*/
/*  my_stack->head = del_node->next;*/
/*  (my_stack->size)--;*/
/*  return del_node;*/
/*}*/
/**/
/*void push(Stack *my_stack, int val) {*/
/*  Node *new_node = (Node *)malloc(sizeof(Node));*/
/*  new_node->val = val;*/
/*  new_node->next = my_stack->head;*/
/*  my_stack->head = new_node;*/
/*}*/
/**/
/*void stack_print(Stack *my_stack) {*/
/*  Node *cur = my_stack->head;*/
/*  do {*/
/*    printf("%d ", cur->val);*/
/*    cur = cur->next;*/
/*  } while (cur != NULL);*/
/*  printf("\n");*/
/*}*/

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
  /*Stack *MyStack = newStack(1);*/
  /*stack_print(MyStack);*/
  /*push(MyStack, 2);*/
  /*push(MyStack, 3);*/
  /*push(MyStack, 4);*/
  /*push(MyStack, 5);*/
  /*push(MyStack, 6);*/
  /*stack_print(MyStack);*/
  /*pop(MyStack);*/
  /*pop(MyStack);*/
  /*pop(MyStack);*/
  /*pop(MyStack);*/
  /*pop(MyStack);*/
  /*stack_print(MyStack);*/

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
