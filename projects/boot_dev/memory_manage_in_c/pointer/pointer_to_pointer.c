#include <stdlib.h>
void allocate_int(int **pointer_pointer, int value) {
  int *new_pointer = malloc(sizeof(int));
  *pointer_pointer = new_pointer;
  **pointer_pointer = value;
}
