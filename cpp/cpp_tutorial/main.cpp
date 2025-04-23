#include <iostream>

int factorial(int a){
  if(a == 1){
    return 1;
  }
  return a * factorial(a-1);
}

int individual_digit_sum(int a){
  if(a == 0){
    return 0;
  }
  return a % 10 + individual_digit_sum(a / 10);
}

int main (int argc, char *argv[]) {
  std::cout << "Enter a number: ";
  int num{};
  std::cin >> num;
  std::cout << "Factorial: " << factorial(num) << std::endl;
  std::cout << "Sum of digits: " << individual_digit_sum(num) << std::endl;
  return 0;
}
