#include "../src/solution.cpp"
#include <umbra/test_cpp.hpp>
#include <vector>

DESCRIBE("Array II", {
  DESCRIBE(
      "1. Set Mismatch",
      {  //
        TEST("TEST CASE 1", {
          vector<int> nums = { 1, 2, 2, 4 };

          vector<int> expected = { 2, 3 };
          vector<int> result = Solution::findErrorNums(nums);

          ASSERT_EQUAL(expected, result);
        });

        TEST("TEST CASE 2", {
          vector<int> nums = { 1, 1 };

          vector<int> expected = { 1, 2 };
          vector<int> result = Solution::findErrorNums(nums);

          ASSERT_EQUAL(expected, result);
        });

        TEST("TEST CASE 3", {
          vector<int> nums = { 2, 2 };

          vector<int> expected = { 2, 1 };
          vector<int> result = Solution::findErrorNums(nums);

          ASSERT_EQUAL(expected, result);
        });


        TEST("TEST CASE 4", {
          vector<int> nums = { 3, 2, 2 };

          vector<int> expected = { 2, 1 };
          vector<int> result = Solution::findErrorNums(nums);

          ASSERT_EQUAL(expected, result);
        });

        TEST("TEST CASE 4", {
          vector<int> nums = { 3, 2, 3, 4, 6, 5 };

          vector<int> expected = { 3, 1 };
          vector<int> result = Solution::findErrorNums(nums);

          ASSERT_EQUAL(expected, result);
        });
      }
  );
});
