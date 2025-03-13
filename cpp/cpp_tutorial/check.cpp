#include <chrono>
#include <iostream>
#include <random>

class Random {
 public:
  static std::mt19937 generate() {
    std::random_device rd;
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(),
        rd(),
        rd(),
        rd(),
        rd(),
        rd(),
        rd()};
    return std::mt19937{ss};
  }
  static std::mt19937 mt{generate()};

  static int get(int min, int max) {
    return std::uniform_int_distribution{min, max}(mt);
  }
};

int main(int argc, char *argv[]) {
  for (int count{1}; count <= 10; ++count)
    std::cout << Random::get(1, 6) << '\t';

  std::cout << '\n';
  return 0;
}
