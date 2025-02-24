#include <iostream>
template <typename T> struct Triad
{
  T first{};
  T second{};
  T third{};
};
template <typename T> void print(Triad<T> triad)
{
  std::cout << triad.first << " " << triad.second << " " << triad.third << "\n";
}

int main()
{
  Triad<int> t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
  print(t1);

  Triad<double> t2{1.2, 3.4,
                   5.6}; // note: uses CTAD to deduce template arguments
  print(t2);

  return 0;
}
