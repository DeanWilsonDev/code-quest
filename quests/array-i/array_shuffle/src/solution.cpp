#include <vector>

using namespace std;

class Solution {
public:
  static vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> solulu;
    int i = 0;
    int j = i + 1;
    int m = n;
    while (solulu.size() < nums.size()) {
      solulu.push_back(nums[i]);
      solulu.push_back(nums[m]);
      m = (j + n) % (nums.size());
      i++;
      j++;
    }
    return solulu;
  }
};
