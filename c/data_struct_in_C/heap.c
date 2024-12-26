#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define INIT_CAP 20

typedef struct Heap {
  int *container;
  int size;
  int cap;
} Heap;

void swap(int *first, int *second);
Heap *heap_init();
int heap_left(int index);
int heap_right(int index);
int heap_parent(int index);
int *heap_peek(Heap *heap);
void *heap_push(Heap *heap, int value);
void *heap_siftUp(Heap *heap, int index);
int *heap_pop(Heap *heap);
void *heap_siftDown(Heap *heap, int index);

Heap *heap_init() {
  int *container = calloc(INIT_CAP, sizeof(int));
  Heap *max_heap = malloc(sizeof(Heap));
  max_heap->container = container;
  max_heap->size = 0;
  max_heap->cap = INIT_CAP;
  return max_heap;
}

int heap_left(int index) {
  int left = index * 2 + 1;
  return left;
}
int heap_right(int index) {
  int right = index * 2 + 2;
  return right;
}
int heap_parent(int index) {
  int parent = (index - 1) / 2;
  return parent;
}
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}

int main(int argc, char *argv[]) {
  int a, b;
  a = 10;
  b = 16;
  int c = heap_parent(b);
  printf("a: %d, b:%d, c: %d\n", a, b, c);
  swap(&a, &b);
  printf("a: %d, b:%d\n", a, b);
  return 0;
}
