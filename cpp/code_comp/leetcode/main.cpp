#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int begin{0};
    int end{static_cast<int>(nums.size()) - 1};
    int mid{end / 2};
    bool isOver{false};
    while (!isOver) {
      if (mid < begin || mid > end) {
        isOver = true;
      } else if (nums[mid] < target) {
        begin = mid + 1;
        mid = begin + (end - begin) / 2;
      } else if (nums[mid] > target) {
        end = mid - 1;
        mid = begin + (end - begin) / 2;
      } else {
        isOver = true;
      }
    }
    if (nums[mid] < target) {
      return mid + 1;
    } else {
      return mid;
    }
  }
};
