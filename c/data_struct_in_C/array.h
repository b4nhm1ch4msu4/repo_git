#include <stdio.h>
#define INIT_CAP 10

typedef struct {
  int size;
  int cap;
  int *arr_ptr;
} MYARRAY;

void arr_print(MYARRAY *arr);
MYARRAY arr_init(int cap);
void arr_expend(MYARRAY *arr);
void arr_insert(MYARRAY *arr, int val, int pos);
int arr_remove(MYARRAY *arr, int val);
int arr_find(MYARRAY *arr, int val);
