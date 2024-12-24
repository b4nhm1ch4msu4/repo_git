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

Node *new_node(int val);
Stack *newStack(int val);
Node *peek(Stack *my_stack);
Node *pop(Stack *my_stack);
void push(Stack *my_stack, Node *new_node);
void stack_print(Stack *my_stack);

Node *new_node(int val){
  Node *new_node = calloc(1,sizeof(Node));
  new_node->next = NULL;
  new_node->val = val;
  return new_node;
}
Stack *newStack(int val) {
  Node *head_node = (Node *)malloc(sizeof(Node));
  head_node->val = val;
  head_node->next = NULL;

  Stack *new_stack = (Stack *)malloc(sizeof(Stack));
  new_stack->head = head_node;
  new_stack->size = 1;
  return new_stack;
}

Node *peek(Stack *my_stack) { return my_stack->head; }

Node *pop(Stack *my_stack) {
  Node *del_node = my_stack->head;
  my_stack->head = del_node->next;
  del_node->next = NULL;
  (my_stack->size)--;
  return del_node;
}

void push(Stack *my_stack, Node *new_node) {
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

int main(int argc, char *argv[])
{

  Stack *MyStack = newStack(1);
  stack_print(MyStack);
  Node *n2 = new_node(2);
  push(MyStack, n2);
  Node *n3 = new_node(3);
  push(MyStack, n3);
  Node *n4 = new_node(4);
  push(MyStack, n4);
  Node *n5 = new_node(5);
  push(MyStack, n5);

  stack_print(MyStack);
  pop(MyStack);
  pop(MyStack);
  stack_print(MyStack);

  return EXIT_SUCCESS;
}
