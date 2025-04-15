#include <iostream>
#include <iterator>

void bubble_sort(int arr[], int length) {
  for (int j = 0; j < length - 1; ++j) {
    bool sorted = true;
    for (int i{0}; i < length - 1 - j; ++i) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        sorted = false;
      }
    }
    if (sorted) {
      std::cout << "sorted after : " << j << std::endl;
      break;
    }
  }
}

void print_arr(int arr[], int length) {
  for (int i{0}; i < length; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int arr[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
  bubble_sort(arr, 9);
  print_arr(arr, 9);
  return 0;
}
