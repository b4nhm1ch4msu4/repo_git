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

void heap_print(Heap *heap);
void swap(int *first, int *second);
Heap *heap_init();
int heap_left(int index);
int heap_right(int index);
int heap_parent(int index);
int *heap_peek(Heap *heap);
void heap_push(Heap *heap, int value);
void heap_siftUp(Heap *heap, int index);
int heap_pop(Heap *heap);
void heap_siftDown(Heap *heap, int index);
Heap *heap_build_from_arr(int *arr, int size);

Heap *heap_init() {
  int *container = calloc(INIT_CAP, sizeof(int));
  Heap *max_heap = malloc(sizeof(Heap));
  max_heap->container = container;
  max_heap->size = 0;
  max_heap->cap = INIT_CAP;
  return max_heap;
}
void heap_print(Heap *my_heap) {
  int cap = my_heap->cap;
  for (int i = 0; i < cap; i++) {
    printf("%d ", my_heap->container[i]);
  }
  printf("\nSize: %d", my_heap->size);
  printf("\nCap: %d", my_heap->cap);
  printf("\n");
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

void heap_siftUp(Heap *heap, int i) {
  while (1) {
    int p = heap_parent(i);
    if (p < 0 || heap->container[i] <= heap->container[p]) {
      break;
    }
    swap(&heap->container[p], &heap->container[i]);
    i = p;
  }
}

void heap_push(Heap *heap, int value) {
  heap->container[heap->size] = value;
  heap->size++;
  heap_siftUp(heap, heap->size - 1);
}

void heap_siftDown(Heap *heap, int i) {
  while (1) {
    int l = heap_left(i);
    int r = heap_right(i);
    int ma = i;
    if (l < heap->size && heap->container[l] > heap->container[ma]) {
      ma = l;
    }
    if (r < heap->size && heap->container[r] > heap->container[ma]) {
      ma = r;
    }
    if (ma == i) {
      break;
    }
    swap(&heap->container[i], &heap->container[ma]);
    i = ma;
  }
}
int heap_pop(Heap *heap) {
  int val = heap->container[0];
  heap->container[0] = heap->container[heap->size - 1];
  heap->container[heap->size - 1] = 0;
  heap->size--;
  heap_siftDown(heap, 0);
  return val;
}

Heap *heap_build_from_arr(int *arr, int size) {
  Heap *my_heap = heap_init();
  my_heap->container = arr;
  my_heap->size = size;
  for (int i = heap_parent(size - 1); i >= 0; i--) {
    heap_siftDown(my_heap, i);
  }
  return my_heap;
}

int main(int argc, char *argv[]) {
  Heap *my_heap = heap_init();
  int arr[INIT_CAP] = {1, 2, 15, 4, 23, 5, 3, 5, 6, 7};
  my_heap->container = arr;
  my_heap->size = 13;
  heap_print(my_heap);
  Heap *new_heap = heap_build_from_arr(arr, 13);
  heap_print(new_heap);

  return 0;
}
