#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade {
  std::string name{};
  char grade{};
};

class GradeMap {
  std::vector<StudentGrade> m_map{};

 public:
  char& operator[](std::string name) {
    auto found = std::find_if(m_map.begin(), m_map.end(),
                              [&](StudentGrade& student) { return student.name == name; });

    if (found != m_map.end())
      return found->grade;

    m_map.push_back({
        name,
    });
    return m_map.back().grade;
  }
};

int main() {
  GradeMap grades{};

  grades["Joe"] = 'A';
  grades["Frank"] = 'B';

  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

  return 0;
}
