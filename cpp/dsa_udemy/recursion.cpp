#include <iostream>

int sum(int n) {
  if (n == 0) {
    return 0;
  }
  return n + sum(n - 1);
};

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int power(int m, int n) {
  if (n == 0) {
    return 1;
  }
  return m * power(m, n - 1);
}

int better_power(int m, int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return better_power(m * m, n / 2);
  }
  return m * better_power(m * m, (n - 1) / 2);
}

int main(int argc, char* argv[]) {
  std::cout << "sum of 5: " << sum(5) << std::endl;
  std::cout << "factorial of 5: " << factorial(5) << std::endl;
  std::cout << "power of 2 and 5: " << power(2, 5) << std::endl;
  std::cout << "better power of 2 and 5: " << better_power(2, 5) << std::endl;
  return 0;
}
