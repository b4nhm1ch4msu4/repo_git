#include <iostream>

using namespace std;

void resize(int *arr, int newSize) { arr = new int[newSize]; }

int main() {
  int *arr = new int[1];
  /*cout << "before change: " << "\n";*/
  /*cout << "arr address : " << &arr << "\n";*/
  /*cout << "arr point to address : " << arr << "\n";*/
  /*cout << "arr value: " << *arr << "\n";*/
 
  resize(arr, 10);
  /*cout << "after change: " << "\n";*/
  /*cout << "arr address : " << &arr << "\n";*/
  /*cout << "arr point to address : " << arr << "\n";*/
  /*cout << "arr value: " << *arr << "\n";*/
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}

