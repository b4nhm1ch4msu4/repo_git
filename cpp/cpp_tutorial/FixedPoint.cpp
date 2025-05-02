#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>

class FixedPoint2 {
  int16_t m_base;
  int8_t m_decimal;

 public:
  FixedPoint2(int16_t base, int8_t decimal) : m_base{base}, m_decimal{decimal} {
    if (base < 0 || decimal < 0) {
      if (base > 0) {
        m_base = -m_base;
      }
      if (decimal > 0) {
        m_decimal = -m_decimal;
      }
    }

    if (std::abs(m_decimal) >= 100) {
      if (m_base < 0) {
        m_base -= std::abs(m_decimal) / 100;
      } else {
        m_base += std::abs(m_decimal) / 100;
      }
      m_decimal = m_decimal % 100;
    }

    // std::cout << "[Constructor] base: " << static_cast<double>(m_base)
    //           << ", decimal: " << static_cast<double>(m_decimal) << '\n';
  }

  FixedPoint2(double d)
      : FixedPoint2(static_cast<std::int16_t>(std::trunc(d)),
                    static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100)) {}

  friend std::ostream& operator<<(std::ostream& os, const FixedPoint2& fp) {
    os << static_cast<double>(fp);
    return os;
  }

  friend bool operator==(const FixedPoint2& lhs, const FixedPoint2& rhs) {
    return lhs.m_base == rhs.m_base && lhs.m_decimal == rhs.m_decimal;
  }

  friend std::istream& operator>>(std::istream& is, FixedPoint2& fp) {
    double d{};
    is >> d;
    fp = FixedPoint2{d};
    return is;
  }

  friend bool testDecimal(const FixedPoint2& fp);

  friend FixedPoint2 operator+(const FixedPoint2& lhs, const FixedPoint2& rhs) {
    return FixedPoint2{static_cast<double>(lhs) + static_cast<double>(rhs)};
  };

  FixedPoint2 operator-() {
    m_base = -m_base;
    m_decimal = -m_decimal;
    return *this;
  }

  operator double() const {
    if (m_base < 0 || m_decimal < 0) {
      return (std::abs(m_base) + std::abs(m_decimal) / 100.0) * (-1.0);
    }
    return (m_base + m_decimal / 100.0);
  }
};

#include <cassert>
#include <iostream>

int main() {
  assert(FixedPoint2{0.75} == FixedPoint2{0.75});     // Test equality true
  assert(!(FixedPoint2{0.75} == FixedPoint2{0.76}));  // Test equality false

  // Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
  assert(FixedPoint2{0.75} + FixedPoint2{1.23} ==
         FixedPoint2{1.98});  // both positive, no decimal overflow
  assert(FixedPoint2{0.75} + FixedPoint2{1.50} ==
         FixedPoint2{2.25});  // both positive, with decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{-1.23} ==
         FixedPoint2{-1.98});  // both negative, no decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{-1.50} ==
         FixedPoint2{-2.25});  // both negative, with decimal overflow
  assert(FixedPoint2{0.75} + FixedPoint2{-1.23} ==
         FixedPoint2{-0.48});  // second negative, no decimal overflow
  assert(FixedPoint2{0.75} + FixedPoint2{-1.50} ==
         FixedPoint2{-0.75});  // second negative, possible decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{1.23} ==
         FixedPoint2{0.48});  // first negative, no decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{1.50} ==
         FixedPoint2{0.75});  // first negative, possible decimal overflow

  FixedPoint2 a{-0.48};
  assert(static_cast<double>(a) == -0.48);
  assert(static_cast<double>(-a) == 0.48);

  std::cout << "Enter a number: ";  // enter 5.678
  std::cin >> a;
  std::cout << "You entered: " << a << '\n';
  assert(static_cast<double>(a) == 5.68);

  return 0;
}
