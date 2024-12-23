#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *head;
  Node *tail;
  int size;
} Queue;

Queue *newQueue(int val);
int peek(Queue *my_queue);
Node *pop(Queue *my_queue);
void push(Queue *my_queue, int val);
void queue_print(Queue *my_queue);

Queue *newQueue(int val) {
  Node *head_node = (Node *)malloc(sizeof(Node));
  head_node->val = val;
  head_node->next = NULL;

  Queue *new_queue = (Queue *)malloc(sizeof(Queue));
  new_queue->head = head_node;
  new_queue->tail = head_node;
  new_queue->size = 1;
  return new_queue;
}

int peek(Queue *my_queue) { return my_queue->head->val; }

Node *pop(Queue *my_queue) {
  if (my_queue->size == 0) {
    return NULL;
  }
  Node *del_node = my_queue->head;
  my_queue->head = del_node->next;
  (my_queue->size)--;
  return del_node;
}

void push(Queue *my_queue, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->val = val;
  my_queue->tail->next = new_node;
  my_queue->tail = new_node;
  my_queue->size++;
}

void queue_print(Queue *my_queue) {
  Node *cur = my_queue->head;
  do {
    printf("%d ", cur->val);
    cur = cur->next;
  } while (cur != NULL);
  printf("\n");
}

/*int main(int argc, char *argv[])*/
/*{*/
/*  Queue *my_queue = newQueue(1);*/
/*  queue_print(my_queue);*/
/*  push(my_queue, 2);*/
/*  push(my_queue, 3);*/
/*  queue_print(my_queue);*/
/*  push(my_queue, 4);*/
/*  push(my_queue, 5);*/
/*  queue_print(my_queue);*/
/**/
/*  pop(my_queue);*/
/**/
/*  queue_print(my_queue);*/
/*  return EXIT_SUCCESS;*/
/*}*/
