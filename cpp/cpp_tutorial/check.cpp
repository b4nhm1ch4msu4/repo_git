#include <iostream>
struct Point3d
{
  double m_x;
  double m_y;
  double m_z;

  /*public:*/
  /*  void setValues(double x, double y, double z)*/
  /*  {*/
  /*    m_x = x;*/
  /*    m_y = y;*/
  /*    m_z = z;*/
  /*  }*/
  void print() const { std::cout << m_x << ", " << m_y << ", " << m_z << '\n'; }
  /*  bool isEqual(const Point3d& other) const*/
  /*  {*/
  /*    return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;*/
  /*  }*/
};

int main(int argc, char* argv[])
{
  Point3d point1{1, 2, 3};
  point1.print();
  return 0;
}
