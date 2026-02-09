#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> findErrorNums(vector<int>& nums) {
    long sum = 0;
    long sumOfSquares = 0;
    size_t n = nums.size();
    long sumToN = n * (n + 1) / 2;
    long sumToNSquared = (n * (n + 1) / 2) * (2 * n + 1) / 3;

    for (size_t i = 0; i < n; ++i) {
      sum += nums[i];
      sumOfSquares += nums[i] * nums[i];
    }

    // d - m
    long eq1 = sum - sumToN;

    // d^2 - m^2
    long eq2 = sumOfSquares - sumToNSquared;

    // d + m
    long eq3 = eq2 / eq1;

    int duplicateNumber = (eq1 + eq3) / 2;
    int missingNumber = (eq3 - eq1) / 2;

    return { duplicateNumber, missingNumber };
  };
};
