#include <iostream>
#include <string>

class MyString {
  std::string str{};

 public:
  MyString(std::string s) : str{s} {}
  friend std::ostream& operator<<(std::ostream& out, const MyString& s) { return out << s.str; }
  std::string operator()(std::size_t index, std::size_t length) const {
    return str.substr(index, length);
  }
};

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
