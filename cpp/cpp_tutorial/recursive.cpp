#include <iostream>

int factorial(int a) {
  if (a == 1) {
    return 1;
  }
  return a * factorial(a - 1);
}

int individual_digit_sum(int a) {
  if (a == 0) {
    return 0;
  }
  return a % 10 + individual_digit_sum(a / 10);
}

std::string decimal2binary(int a) {
  if (a < 0) {
    return decimal2binary(-a);
  }
  if (a == 0) {
    return "0";
  }
  return decimal2binary(a / 2) + std::to_string(a % 2);
}

int main(int argc, char* argv[]) {
  std::cout << "Enter a number: ";
  int num{};
  std::cin >> num;
  // std::cout << "Factorial: " << factorial(num) << std::endl;
  // std::cout << "Sum of digits: " << individual_digit_sum(num) << std::endl;
  std::string bin_num{decimal2binary(num)};
  if (bin_num[0] == '0' && bin_num.size() > 1) {
    bin_num = bin_num.substr(1);
  }
  std::cout << "Binary: " << bin_num << std::endl;
  return 0;
}
