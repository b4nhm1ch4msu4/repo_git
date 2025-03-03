#include <iostream>
class Foo
{
public:
  Foo(int x, int y = 0) : m_value{x}, m_another_value{y}
  {
    std::cout << "Foo constructor\n";
  }
  ~Foo() { std::cout << "Foo destructor\n"; }

private:
  int m_value;
  int m_another_value;
};

int main(int argc, char* argv[])
{
  Foo f{1, 2};
  return 0;
}
