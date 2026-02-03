#include <vector>
using namespace std;

class Solution {
public:
  static int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0;
    int maxConsecutiveCount = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        count++;
        if (maxConsecutiveCount < count) {
          maxConsecutiveCount = count;
        }
      }
      if (nums[i] == 0) {
        count = 0;
      }
    }

    return maxConsecutiveCount;
  }
};
