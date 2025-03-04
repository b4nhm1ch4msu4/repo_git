#ifndef Ball
#define Ball

#include <string>
#include <string_view>

class Ball
{
public:
  Ball(std::string_view color, double radius 10.0);

  Ball(double radius) : Ball{"black", radius} {}
  std::string getColor() const;
  double getRadius() const;

private:
  std::string m_color;
  double m_radius;
};

void print(const Ball& ball);
#endif // Ball
