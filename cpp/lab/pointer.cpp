#include <iostream>
using namespace std;

void resize(int *array_address2, int size) {
  std::cout << "[Resize] array_address2 address (itslef): " << &array_address2
            << "\n";
  std::cout << "[Resize] array_address2 size : " << sizeof(array_address2)
            << "\n";
  std::cout << "[Resize] array_address2 point to address : " << array_address2
            << "\n";
  std::cout << "[Resize] value : " << *array_address2 << "\n";
  std::cout << "============================================================\n";

  array_address2 = new int[size];

  std::cout << "[Resize] array_address2 address (itslef): " << &array_address2
            << "\n";
  std::cout << "[Resize] array_address2 size : " << sizeof(array_address2)
            << "\n";
  std::cout << "[Resize] array_address2 point to address : " << array_address2
            << "\n";
  std::cout << "[Resize] value : " << *array_address2 << "\n";
  std::cout << "============================================================\n";
}

int main() {
  int aiArray[1];
  int *int_pointer = &aiArray[0];

  int *arr = new int[1];

  // Array first item's address is the same as pointer
  std::cout << "[Main] Integer Pointer address (itslef): " << &int_pointer
            << "\n";
  std::cout << "[Main] Integer Pointer size : " << sizeof(int_pointer) << "\n";
  std::cout << "[Main] Integer Pointer point to address : " << int_pointer
            << "\n";
  std::cout << "[Main] Integer array address : " << &aiArray[0] << "\n";
  std::cout << "============================================================\n";

  //  Use the pointer to change the value in array
  *int_pointer = 10;
  std::cout << "[Main] aiArray[0] value : " << aiArray[0] << "\n";
  std::cout << "[Main] Pointer value : " << *int_pointer << "\n";
  std::cout << "============================================================\n";

  // Call resize function
  resize(arr, 100);

  // Pointer to another array
  int aiArray2[13];
  int_pointer = &aiArray2[0];
  std::cout << "[Main] Integer Pointer address (itslef): " << &int_pointer
            << "\n";
}
