#include <iostream>

using namespace std;

class Animal {
public:
  virtual void makeSound() { std::cout << "animal sound!!" << '\n'; }
};

class Dog : public Animal {
public:
  void makeSound() { std::cout << "gou gou" << '\n'; }
};

int main(int argc, char *argv[]) {
  Animal *a;
  // a->makeSound();
  Dog d;
  d.makeSound();
  a = &d;
  a->makeSound();
  return 0;
}
