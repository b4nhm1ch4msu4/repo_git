#include "date.h"

#include <iostream>

Date::Date(int day, int month, int year)
    : m_day{day}, m_month{month}, m_year{year} {}

void Date::print() const {
  std::cout << m_day << '/' << m_month << '/' << m_year << '\n';
}
