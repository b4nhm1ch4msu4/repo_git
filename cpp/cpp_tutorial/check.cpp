#include <iostream>
#include <string_view>
enum class Animal
{
  pig,
  chicken,
  goat,
  cat,
  dog,
  duck,
};

std::string_view getAnimalName(Animal a)
{
  switch (a)
  {
  case Animal::pig:
    return "pig";
  case Animal::chicken:
    return "chicken";
  case Animal::goat:
    return "goat";
  case Animal::cat:
    return "cat";
  case Animal::dog:
    return "dog";
  case Animal::duck:
    return "duck";
  default:
    return "unknown";
  }
}

void printNumberOfLegs(Animal a)
{
  switch (a)
  {
  case Animal::pig:
  case Animal::goat:
  case Animal::cat:
  case Animal::dog:
    std::cout << "A " << getAnimalName(a) << " has " << "4 " << "legs.\n";
    break;
  case Animal::chicken:
  case Animal::duck:
    std::cout << "A " << getAnimalName(a) << " has " << "2 " << "legs.\n";
    break;
  default:
    std::cout << "unknown\n";
  }
}
int main(int argc, char* argv[])
{

  printNumberOfLegs(Animal::cat);
  printNumberOfLegs(Animal::chicken);
  return 0;
}
