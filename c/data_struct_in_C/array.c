#include <stdio.h>

#define INIT_CAP 10

typedef struct {
  int length;
  int cap;
  int *arr;
} ARRAY;

// Khởi tạo Array
int arr_init(ARRAY *my_arr_ptr) {
  my_arr_ptr->length = 0;
  my_arr_ptr->cap = INIT_CAP;
  int arr[my_arr_ptr->cap];
  my_arr_ptr->arr = arr;
  for (int i = 0; i < my_arr_ptr->cap; i++) {
    my_arr_ptr->arr[i] = 0;
  }
  return 0;
}

// Thêm phần tử vào arr
// độ dài của array là cố định, khi thêm một phần tử vào giữa array, các p.tử
// bên phải sẽ dịch chuyển sang 1 đơn vị
int arr_insert(ARRAY *my_arr_ptr, int val, int pos) {
  if (my_arr_ptr->length + 1 > my_arr_ptr->cap) {
    return -1;
  }

  for (int i = my_arr_ptr->length; i > pos; i--) {
    my_arr_ptr->arr[i] = my_arr_ptr->arr[i - 1];
  }
  my_arr_ptr->arr[pos] = val;
  ++(my_arr_ptr->length);
  return 0;
}

// Xóa 1 p.tử khỏi array.
int arr_remove(int arr[], int *length, int *cap, int pos) {
  if (*length < 1) {
    return -1;
  }
  for (int i = pos; i < *length; i++) {
    arr[i] = arr[i + 1];
  }
  --(*length);
  return 0;
}

// Tìm kiếm p.tử trong array
int arr_find(int arr[], int *length, int *cap, int val) {
  for (int i = 0; i < *length; i++) {
    if (arr[i] == val) {
      printf("found val: %d at position: %d\n", val, i);
      return 0;
    }
  }
  return -1;
}

// Mở rộng array
int arr_expend(ARRAY *my_arr_ptr) {
  int new_arr[my_arr_ptr->cap * 2];
  for(int i = 0; i < my_arr_ptr->length; i++){
    new_arr[i] = my_arr_ptr->arr[i];
  }
  my_arr_ptr->arr = new_arr;
  return 0;
}

// In các p.tử của mảng
void arr_print(ARRAY *my_arr_ptr) {
  printf("Array :");
  for (int i = 0; i < my_arr_ptr->cap; i++) {
    printf("%d ", my_arr_ptr->arr[i]);
  }
  printf("\n");
  printf("Length: %d\n", my_arr_ptr->length);
  printf("Capacity: %d\n", my_arr_ptr->cap);
}

/////////////////////////
///// MAIN FUNCTION /////
/////////////////////////
int main(int argc, char *argv[]) {

  ARRAY container;
  ARRAY *my_arr_ptr = &container;
  arr_init(my_arr_ptr, container);
  for(int i = 1; i <= 5; i++){
    my_arr_ptr->arr[i] = i;
    my_arr_ptr->length++;
  }
  arr_print(my_arr_ptr);
  arr_insert(my_arr_ptr, 10, 4);
  arr_print(my_arr_ptr);

  return 0;
}
