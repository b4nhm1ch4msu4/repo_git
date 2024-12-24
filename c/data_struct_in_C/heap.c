typedef struct Heap{
  int *container;
  int size;
  int cap;
} Heap;

Heap *heap_init();
Heap *heap_left(Heap *)
