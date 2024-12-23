#include <stdlib.h>
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

/*
 * description:
 * input:
 * output:
 */

/*
 * description: Print all elements in MYARRAY
 * input: MYARRAY need to print elements
 * output: none
 */
void arr_print(MYARRAY *arr) {
  for (int i = 0; i < arr->cap; i++) {
    printf("%d ", arr->arr_ptr[i]);
  }
  printf("\n");
  printf("Size: %d\nCapacity: %d\n", arr->size, arr->cap);
}

/*
 * description: Create new MYARRAY
 * input: array capacity
 * output: MYARRAY
 */
MYARRAY arr_init(int cap) {
  int *arr_ptr = (int *)calloc(cap, sizeof(int));
  MYARRAY my_arr = {0, cap, arr_ptr};
  return my_arr;
}
/*
 * description: find a value in MYARRAY
 * input:
 *  arr: pointer to MYARRAY
 *  val: value to find
 * output: the position of value, if value not in MYARRAY return -1
 *
 */
int arr_find(MYARRAY *arr, int val) {
  for (int i = 0; i < arr->size; i++) {
    if (arr->arr_ptr[i] == val) {
      printf("found val %d at position %d\n", val, i);
      return i;
    }
  }
  printf("val %d not in array!!!\n", val);
  return -1;
}

/*
 * description:
 *  Insert a value to specifix position in MYARRAY
 *  Expend MYARRAY if not enough space
 * input:
 *  arr: pointer to MYARRAY
 *  val: value of element to Insert
 *  pos: position where we want to insert value
 * output: none
 */
void arr_insert(MYARRAY *arr, int val, int pos) {
  if ((arr->size + 1) > arr->cap) {
    arr_expend(arr);
  }

  // if position out of size, add value at the end of MYARRAY
  if (pos > arr->size) {
    arr->arr_ptr[arr->size] = val;
  }
  // if MYARRAY is empty, add value at beginning of MYARRAY
  else if (arr->size == 0) {
    arr->arr_ptr[0] = val;
  } 
  // if position in middle of middle of MYARRAY shifting all subsequent elements back by one position
  else {
    for (int i = arr->size; i > pos; i--) {
      arr->arr_ptr[i] = arr->arr_ptr[i - 1];
    }
    arr->arr_ptr[pos] = val;
  }

  arr->size++;
}

/*
 * description: remove a val if it exist in MYARRAY
 * input:
 *  arr: pointer to MYARRAY
 *  val: value want to remove
 * output:
 *  return -1 if value not exist in MYARRAY
 *  else return 0 (success)
 */
int arr_remove(MYARRAY *arr, int val) {
  int pos = arr_find(arr, val);
  if (pos == -1) {
    return -1;
  }
  for (int i = pos; i < (arr->size) - 1; i++) {
    arr->arr_ptr[i] = arr->arr_ptr[i + 1];
  }
  arr->size--;
  arr->arr_ptr[arr->size] = 0;
  return 0;
}

/*
 * description:double capacity of MYARRAY
 * input: arr: pointer to MYARRAY
 * output: none
 */
void arr_expend(MYARRAY *arr) {
  int new_cap = arr->cap * 2;
  arr->arr_ptr = realloc(arr->arr_ptr, sizeof(int[new_cap]));
  arr->cap = new_cap;
}

/////////////////////////////
///// MAIN ENTRY POINT /////
////////////////////////////
int main(int argc, char *argv[]) {
  MYARRAY my_arr = arr_init(5);
  MYARRAY *my_arr_ptr = &my_arr;
  arr_print(my_arr_ptr);
  /*arr_find(my_arr_ptr, 20);*/
  arr_insert(my_arr_ptr, 1, 1);
  arr_insert(my_arr_ptr, 2, 10);
  arr_insert(my_arr_ptr, 3, 10);
  arr_insert(my_arr_ptr, 4, 10);
  arr_insert(my_arr_ptr, 5, 10);
  arr_print(my_arr_ptr);
  arr_insert(my_arr_ptr, 6, 10);
  arr_insert(my_arr_ptr, 7, 10);
  arr_insert(my_arr_ptr, 8, 10);
  arr_insert(my_arr_ptr, 9, 10);
  arr_insert(my_arr_ptr, 10, 10);
  /*arr_remove(my_arr_ptr, 0);*/
  arr_print(my_arr_ptr);

  free(my_arr_ptr->arr_ptr);
  my_arr_ptr = NULL;
  return 0;
}
