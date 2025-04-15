#include <algorithm>
#include <array>
#include <iostream>
#include <thread>
#include "Timer.h"

bool greater(int a, int b) {
  return (a < b);
}

int main() {
  std::array arr{13, 90, 99, 5, 40, 80};
  Timer t;
  std::sort(arr.begin(), arr.end(), greater);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Time elapsed: " << t.elapsed() << " seconds\n";
  for (auto i : arr) {
    std::cout << i << " ";
  }
}
