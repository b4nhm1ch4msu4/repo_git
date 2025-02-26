#include <iostream>
struct IntPair
{
  int first{};
  int second{};
  void print() const { std::cout << first << ' ' << second << '\n'; }
  bool isEqual(const IntPair& other) const
  {
    return first == other.first && second == other.second;
  }
};

int main(int argc, char* argv[])
{
  const IntPair p1{1, 2};
  IntPair p2{1, 4};

  std::cout << "p1: ";
  p1.print();

  std::cout << "p2: ";
  p2.print();

  std::cout << "p1 and p1 "
            << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
  std::cout << "p1 and p2 "
            << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");
  return 0;
}
