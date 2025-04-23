#include <functional>
#include <iostream>
#include <limits>

int get_number() {
  int num{};
  std::cout << "Enter a number: ";
  std::cin >> num;
  return num;
}

char get_operator() {
  char op{};
  do {
    std::cout << "Choose operator: + , - , * , /: ";
    std::cin >> op;
  } while (op != '+' && op != '-' && op != '*' && op != '/');
  return op;
}

int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op) {
  switch (op) {
    case '+':
      return add;
    case '-':
      return subtract;
    case '*':
      return multiply;
    case '/':
      return divide;
    default:
      return nullptr;
  }
}

int main(int argc, char* argv[]) {
  int a{get_number()};
  char op{get_operator()};
  int b{get_number()};
  std::cout << getArithmeticFunction(op)(a, b) << std::endl;
  return 0;
}
