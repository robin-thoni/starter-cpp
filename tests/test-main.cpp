#include <iostream>
#include <string.h>
#include <gtest/gtest.h>

TEST(None, None)
{
  ASSERT_TRUE(true);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
