#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>

// bool greater(int a, int b) { return (a < b); }
// bool less(int a, int b) { return (a < b); }
void selection_sort(int arr[], int length,std::function<bool(int,int)> compare) {
  for (int i{0}; i < length - 1; ++i) {
    int least_index{i};
    for (int j{i + 1}; j < length; ++j) {
      if (compare(arr[j], arr[least_index])) {
        least_index = j;
      }
    }
    std::swap(arr[least_index], arr[i]);
  }

}

// void selection_sort(int arr[], int length, bool reverse = false) {
//   if (reverse) {
//     for (int i{0}; i < length - 1; ++i) {
//       int max_index{i};
//       for (int j{i + 1}; j < length; ++j) {
//         if (arr[j] > arr[max_index]) {
//           max_index = j;
//         }
//       }
//       std::swap(arr[max_index], arr[i]);
//     }
//   } else {
//     for (int i{0}; i < length - 1; ++i) {
//       int min_index{i};
//       for (int j{i + 1}; j < length; ++j) {
//         if (arr[j] < arr[min_index]) {
//           min_index = j;
//         }
//       }
//       std::swap(arr[min_index], arr[i]);
//     }
//   }
// }

void print_arr(int arr[], int length) {
  for (int i{0}; i < length; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int arr[]{42, 17, 93, 5, 71, 28, 84, 36, 59, 12, 67, 3, 45, 91, 22, 78, 54, 9, 63, 30};
  int length{std::size(arr)};
  selection_sort(arr, length,std::greater{});
  print_arr(arr, length);
  return 0;
}
