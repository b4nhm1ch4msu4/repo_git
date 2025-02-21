#include <iostream>
#include <string>

struct Employee
{
  std::string name;
  int id{};
};

std::ostream& operator<<(std::ostream& out, const Employee& e)
{
  return out << e.name << " has id is " << e.id;
}

int main(int argc, char* argv[])
{
  Employee joe{.name = "Joe", .id = 1};
  std::cout << joe << "\n";

  joe.id = 2;
  joe.name = "John";
  std::cout << joe << "\n";
  return 0;
}
