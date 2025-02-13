#include <algorithm>
#include <iostream>

using namespace std;

class Student
{
private:
  string name;
  int age;

public:
  Student(string name, int age)
  {
    static int count = 0;
    this->name = name;
    this->age = age;
    count++;
  }
};

int main()
{
  Student s1("Manh", 19);
  Student s2("Trung", 19);
  cout << Student::numberOfStudents << '\n';
  return 0;
}
