#include <iostream>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(&arr[i], &arr[min_idx]);
  }
}

int main(int argc, char *argv[]) {
  int arr[]{2, 5, 4, 3, 10, 20, 15, 8, 1};
  selection_sort(arr, 9);
  for (int item : arr) {
    std::cout << item << '\t';
  }
  return 0;
}
