#include "../src/solution.cpp"
#include <umbra/test_cpp.hpp>
#include <vector>

DESCRIBE(
    "Array I",
    { //
      DESCRIBE("3. Max Consecutive Ones", {
        TEST("TEST CASE 1", {  //
          vector<int> nums = { 1, 1, 0, 1, 1, 1 };

          int expected = 3;
          int result = Solution::findMaxConsecutiveOnes(nums);

          ASSERT_EQUAL(expected, result);
        });

        TEST("TEST CASE 2", {
          vector<int> nums = { 1, 0, 1, 1, 0, 1 };

          int expected = 2;
          int result = Solution::findMaxConsecutiveOnes(nums);

          ASSERT_EQUAL(expected, result);
        });
      }) }
);
