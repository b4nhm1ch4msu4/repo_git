#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int contain_vowel(string s, char c) {
      int count = 0;
      for (char ch : s) {
        if (ch == c) {
          ++count;
        }
      }
      return count;
    }
  int countOfSubstrings(string word, int k) {
    size_t word_size = word.size();
    int result = 0;
    for (int j = 0;j <= word_size - k - 5; j++) {
      string sub_string = word.substr(j, k + 5);
      int a = contain_vowel(sub_string, 'a');
      int e = contain_vowel(sub_string, 'e');
      int i = contain_vowel(sub_string, 'i');
      int o = contain_vowel(sub_string, 'o');
      int u = contain_vowel(sub_string, 'u');
      if(a >= 1 && e >= 1 && i >= 1 && o >= 1 && u >= 1 && (a + e + i + o + u == k)) {
        result++;
      }
    }
    return result;
  }
};
