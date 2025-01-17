/*#include "check.cpp"*/
#include <cstdio>
#include <iostream>
#include <istream>
#include <string>

extern int myage;

int main(int argc, char *argv[]) {
  std::cout << myage;
  int age_1{};
  int age_2{};
  std::string name_1{};
  std::string name_2{};
  std::cout << "Enter your name 1: ";
  std::getline(std::cin >> std::ws, name_1);
  std::cout << "Enter your age 1: ";
  std::cin >> age_1;

  std::cout << "Enter your name 2: ";
  std::getline(std::cin >> std::ws, name_2);
  std::cout << "Enter your age 2: ";
  std::cin >> age_2;
  if (age_1 > age_2) {
    std::cout << name_1 << " (age " << age_1 << ") is older than " << name_2
              << " (age " << age_2 << ").";
  } else {
    std::cout << name_2 << " (age " << age_2 << ") is older than " << name_1
              << " (age " << age_1 << ").";
  }

  return 0;
}
