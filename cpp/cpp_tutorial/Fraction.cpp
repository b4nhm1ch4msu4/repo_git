#include <iostream>
class Fraction {
 public:
  explicit Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {}
  void getFraction() {
    std::cout << "Enter a value for numerator: ";
    std::cin >> m_numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> m_denominator;
    std::cout << "Fraction(" << m_numerator << "/ " << m_denominator
              << ") was created" << '\n';
  }

  Fraction multiply(const Fraction &f) const {
    return Fraction{m_numerator * f.m_numerator,
                    m_denominator * f.m_denominator};
  }

  void print() const {
    std::cout << "Fraction(" << m_numerator << "/ " << m_denominator << ")\n";
  }

 private:
  int m_numerator{0};
  int m_denominator{1};
};

int main(int argc, char *argv[]) {
  Fraction f1;
  f1.getFraction();
  Fraction f2;
  f2.getFraction();
  f1.multiply(f2).print();
  return 0;
}
