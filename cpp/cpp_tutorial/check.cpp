#include <iostream>
class Foo
{
public:
  Foo(int x) : m_value{x} { std::cout << "Foo constructor\n"; }
  ~Foo() { std::cout << "Foo destructor\n"; }

private:
  int m_value;
};

int main(int argc, char* argv[])
{
  Foo f{1};
  return 0;
}
