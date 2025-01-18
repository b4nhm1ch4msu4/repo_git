#include <algorithm>
#include <iterator>
#include <string>

class Solution {
public:
  bool isPalindrome(int x) {
    const std::string str = std::to_string(x);
    return std::equal(std::begin(str), std::end(str), std::rbegin(str));
  }
};
