#include <array>
#include <iostream>

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
constexpr int rowLength(const Array2d<T, Row, Col>&) {
  return Row;
}

template <typename T, std::size_t Row, std::size_t Col>
constexpr int colLength(const Array2d<T, Row, Col>&) {
  return Col;
}

int main(int argc, char* argv[]) {
  Array2d<int, 4, 3> my_2dArray = {{
      {1, 2, 3},
      {1, 2, 3},
      {1, 2, 3},
      {1, 2, 3},
  }};
  std::cout<< "array row: " << rowLength(my_2dArray) << "\n";
  std::cout<< "array col: " << colLength(my_2dArray) << "\n";
  for(auto& row:my_2dArray){
    for(auto& item:row){
      std::cout << item << ' ';
    }
    std::cout << "\n";
  }
  return 0;
}
