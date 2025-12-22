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

Node *new_node(int val);
Queue *newQueue();
int peek(Queue *my_queue);
Node *pop(Queue *my_queue);
void push(Queue *my_queue, Node *new_node);
void queue_print(Queue *my_queue);

Node *new_node(int val) {
  Node *new_node = calloc(1, sizeof(Node));
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}
Queue *newQueue() {
  Queue *new_queue = (Queue *)malloc(sizeof(Queue));
  new_queue->head = NULL;
  new_queue->tail = NULL;
  new_queue->size = 0;
  return new_queue;
}

int peek(Queue *my_queue) { return my_queue->head->val; }

Node *pop(Queue *my_queue) {
  if (my_queue->size == 0) {
    return NULL;
  }
  Node *del_node = my_queue->head;
  my_queue->head = del_node->next;
  del_node->next = NULL;
  (my_queue->size)--;
  return del_node;
}

void push(Queue *my_queue, Node *new_node) {
  if (my_queue->head == NULL) {
    my_queue->head = new_node;
    my_queue->tail = new_node;
  } else {
    my_queue->tail->next = new_node;
    my_queue->tail = new_node;
  }
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

int main(int argc, char *argv[]) {
  Node *n1 = new_node(1);
  Node *n2 = new_node(2);
  Node *n3 = new_node(3);
  Node *n4 = new_node(4);
  Node *n5 = new_node(5);
  Queue *my_queue = newQueue();
  push(my_queue, n1);
  push(my_queue, n2);
  queue_print(my_queue);
  push(my_queue, n3);
  push(my_queue, n4);
  push(my_queue, n5);
  queue_print(my_queue);

  Node *head = pop(my_queue);
  printf("last node value: %d\n", head->val);

  queue_print(my_queue);
  return EXIT_SUCCESS;
}
