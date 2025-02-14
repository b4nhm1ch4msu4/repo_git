#include <iostream>

using namespace std;

class Student
{
private:
  string name;
  int age;

public:
  static int count;
  Student(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
};

int main()
{
  Student s1("Manh", 19);
  Student s2("Trung", 19);
  std::cout << "Hello World" << '\n';
  return 0;
}
