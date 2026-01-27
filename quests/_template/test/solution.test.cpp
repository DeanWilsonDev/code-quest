#include "../src/solution.cpp"
#include <umbra/test_cpp.hpp>

DESCRIBE("Template Example Tests", {
  TEST("TEST CASE 1", { ASSERT_EQUAL(1 + 1, 2); });

  TEST("TEST CASE 2", {
    bool isTrue = true;
    ASSERT_TRUE(isTrue);
  });
});
