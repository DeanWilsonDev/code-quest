#include <vector>

using namespace std;

class Solution {
public:
  static vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> shuffledNums;
    int i = 0;
    int j = i + 1;
    int m = n;
    while (shuffledNums.size() < nums.size()) {
      shuffledNums.push_back(nums[i]);
      shuffledNums.push_back(nums[m]);
      m = (j + n) % (nums.size());
      i++;
      j++;
    }
    return shuffledNums;
  }
};
