/*#include <iostream>*/
/**/
/*using namespace std;*/
/**/
/*void resize(int *arr, int newSize) {*/
/*  // allocate arr to new pointer*/
/*  arr = new int[newSize];*/
/*}*/
/**/
/*int main() {*/
/*  int *arr = new int[1];*/
/*  resize(arr, 10);*/
/**/
/*  for (int i = 0; i < 10; i++) {*/
/*    arr[i] = i;*/
/*  }*/
/*  for (int i = 0; i < 10; i++) {*/
/*    cout << arr[i] << " ";*/
/*  }*/
/*  delete[] arr;*/
/*  return 0;*/
/*}*/

#include <iostream>

using namespace std;

void resize(int *arr, int newSize) {
  // allocate arr to new pointer*/
  /*delete[] arr;*/
  /*cout << arr << endl;*/
  arr = new int[newSize];
  /*cout << arr << endl;*/
  /*arr = new int[newSize + 10];*/
  /*cout << "address of arr: " << arr << "\n";*/
}

int main() {
  int *arr = new int[1];
  cout << arr << endl;
  for (int i = 0; i < 10; i++) {
    cout << arr[i];
  }
  resize(arr, 10);
  /*cout << &arr[0] << "\n";*/
  cout << arr << endl;
  delete[] arr;
  return 0;
}
