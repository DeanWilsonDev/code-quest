#include "../src/solution.cpp"
#include <umbra/test_cpp.hpp>
#include <vector>

DESCRIBE("Array I Tests", {
  TEST("TEST CASE 1", {
    (void)user;
    std::vector<int> nums = {1, 2, 1};
    std::vector<int> result = Solution::getConcatenation(nums);
    std::vector<int> expected = {1, 2, 1, 1, 2, 1};
    // MAIN QUEST: Add Assertions for array comparisons

    // ASSERT_EQUAL_INT(expected, result);
    ASSERT_TRUE(false);
  });

  TEST("TEST CASE 2", {
    (void)user;
    std::vector<int> nums = {1, 3, 2, 1};
    std::vector<int> result = Solution::getConcatenation(nums);
    std::vector<int> expected = {1, 3, 2, 1, 1, 3, 2, 1};

    // ASSERT_EQUAL_INT(expected, result);
    ASSERT_TRUE(false);
  });
});
