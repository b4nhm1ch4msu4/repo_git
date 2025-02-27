#include <iostream>
#include <string>
#include <string_view>

class Employee
{
  std::string m_name{};

public:
  void setName(std::string_view name) { m_name = name; }
  const std::string& getName() const
  {
    return m_name;
  } //  getter returns by const reference
};

Employee createEmployee(std::string_view name)
{
  Employee e;
  e.setName(name);
  return e;
}

int main(int argc, char* argv[]) { return 0; }
