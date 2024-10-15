#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int midx = m - 1;
    int nidx = n - 1;
    int right = m + n - 1;
    while (nidx >= 0) {
      if (midx >= 0 && nums1[midx] > nums2[nidx]) {
        nums1[right] = nums1[midx];
        midx--;
      } else {
        nums1[right] = nums2[nidx];
        nidx--;
      }
      right--;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution sol = Solution();
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 4, 5};
  sol.merge(nums1, 3, nums2, 3);
  for (int item : nums1) {
    cout << item << endl;
  }
  return 0;
}
