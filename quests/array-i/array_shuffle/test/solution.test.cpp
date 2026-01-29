#include "../src/solution.cpp"
#include <umbra/test_cpp.hpp>

DESCRIBE("Array I Tests", {
  DESCRIBE("Array Shuffle", {
    TEST("TEST CASE 1", {
      vector<int> input = {2, 5, 1, 3, 4, 7};
      int n = 3;
      vector<int> expected = {2, 3, 5, 4, 1, 7};

      vector<int> result = Solution::shuffle(input, n);

      ASSERT_EQUAL(expected, result);
    });

    TEST("TEST CASE 2", {
      vector<int> input = {1, 2, 3, 4, 4, 3, 2, 1};
      int n = 4;
      vector<int> expected = {1, 4, 2, 3, 3, 2, 4, 1};

      vector<int> result = Solution::shuffle(input, n);
      ASSERT_EQUAL(expected, result);
    });

    TEST("TEST CASE 3", {
      vector<int> input = {1, 1, 2, 2};
      int n = 2;
      vector<int> expected = {1, 2, 1, 2};

      vector<int> result = Solution::shuffle(input, n);

      ASSERT_EQUAL(expected, result);
    });
  });
})
