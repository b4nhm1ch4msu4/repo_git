#include <stdio.h>
#include <stdlib.h>

// Linked_List-based

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *head;
  int size;
} Stack;

Stack *newStack(int val);
int peek(Stack *my_stack);
Node *pop(Stack *my_stack);
void push(Stack *my_stack, int val);
void stack_print(Stack *my_stack);

Stack *newStack(int val) {
  Node *head_node = (Node *)malloc(sizeof(Node));
  head_node->val = val;
  head_node->next = NULL;

  Stack *new_stack = (Stack *)malloc(sizeof(Stack));
  new_stack->head = head_node;
  new_stack->size = 1;
  return new_stack;
}

int peek(Stack *my_stack) { return my_stack->head->val; }

Node *pop(Stack *my_stack) {
  Node *del_node = my_stack->head;
  my_stack->head = del_node->next;
  (my_stack->size)--;
  return del_node;
}

void push(Stack *my_stack, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->val = val;
  new_node->next = my_stack->head;
  my_stack->head = new_node;
}

void stack_print(Stack *my_stack) {
  Node *cur = my_stack->head;
  do {
    printf("%d ", cur->val);
    cur = cur->next;
  } while (cur != NULL);
  printf("\n");
}
/////////////////////////////
///// MAIN ENTRY POINT /////
////////////////////////////
int main(int argc, char *argv[]) {
  Stack *MyStack = newStack(1);
  stack_print(MyStack);
  push(MyStack, 2);
  push(MyStack, 3);
  push(MyStack, 4);
  push(MyStack, 5);
  push(MyStack, 6);
  stack_print(MyStack);
  pop(MyStack);
  pop(MyStack);
  pop(MyStack);
  pop(MyStack);
  pop(MyStack);
  stack_print(MyStack);

  return 0;
}
// Array-based
