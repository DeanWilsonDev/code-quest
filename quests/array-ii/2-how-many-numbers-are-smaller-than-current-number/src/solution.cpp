#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> result(nums.size(), 0);

    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = 0; j < nums.size(); ++j) {
        result[i] += nums[i] > nums[j] ? 1 : 0;
      }
    }
    return result;
  }
};
