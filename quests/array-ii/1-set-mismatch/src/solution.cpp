#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> findErrorNums(vector<int>& nums) {
    vector<int> output;
    int previousValue = 0;
    int index = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[index] == previousValue) {
        output = { nums[index], index };
        break;
      }
      previousValue = nums[index];
      index++;
    }

    return output;
  };
};
