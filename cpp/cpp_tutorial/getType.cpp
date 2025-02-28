#include <iostream>
#include <string_view>

template <class T> constexpr std::string_view type_name()
{
  using namespace std;
#ifdef __clang__
  string_view p = __PRETTY_FUNCTION__;
  return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
  string_view p = __PRETTY_FUNCTION__;
#if __cplusplus < 201402
  return string_view(p.data() + 36, p.size() - 36 - 1);
#else
  return string_view(p.data() + 49, p.find(';', 49) - 49);
#endif
#elif defined(_MSC_VER)
  string_view p = __FUNCSIG__;
  return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

class Foo
{
private:
  int m_value{4}; // private member

public:
  int& value()
  {
    return m_value;
  } // returns a non-const reference (don't do this)
};

int main()
{
  Foo f{};       // f.m_value is initialized to default value 4
  f.value() = 5; // The equivalent of m_value = 5
  auto t{f.value()};
  std::cout << type_name<decltype(t)>() << std::endl;
  return 0;
}
