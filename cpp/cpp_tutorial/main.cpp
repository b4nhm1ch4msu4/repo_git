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
  Employee joe{"Joe", 1};
  std::cout << joe << "\n";
  return 0;
}
