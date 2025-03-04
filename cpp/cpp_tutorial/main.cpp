#include <iostream>
#include <string_view>

class Ball
{
public:
  Ball(std::string_view color = "black", double radius = 10.0)
      : m_color{color}, m_radius{radius}
  {
    print();
  }

  Ball(double radius) : Ball{"black", radius} {}
  void print()
  {
    std::cout << "Ball (" << m_color << ", " << m_radius << ")\n";
  }

private:
  std::string m_color;
  double m_radius;
};

int main()
{
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20.0};
  Ball blueTwenty{"blue", 20.0};

  return 0;
}
