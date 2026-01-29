#include "../src/solution.cpp"
#include <umbra/test_cpp.hpp>
#include <vector>

DESCRIBE("Array I Tests", {
  DESCRIBE("Concatenate Array", {
    TEST("TEST CASE 1", {
      (void)user;
      std::vector<int> nums = {1, 2, 1};
      std::vector<int> result = Solution::getConcatenation(nums);
      std::vector<int> expected = {1, 2, 1, 1, 2, 1};

      ASSERT_EQUAL(expected, result);
    });

    TEST("TEST CASE 2", {
      (void)user;
      std::vector<int> nums = {1, 3, 2, 1};
      std::vector<int> result = Solution::getConcatenation(nums);
      std::vector<int> expected = {1, 3, 2, 1, 1, 3, 2, 1};

      ASSERT_EQUAL(expected, result);
    });
  });
});
