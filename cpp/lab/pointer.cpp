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
  arr = new int[newSize];
}

int main() {
  int *arr = new int[1];
  cout << arr << endl;
  resize(arr, 10);
  cout << arr << endl;
  delete[] arr;
  return 0;
}
