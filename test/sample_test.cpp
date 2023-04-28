#include <gtest/gtest.h>
#include "sample.hpp"
#include <iostream>


TEST (sample_test, sample_test) {
    int a = 10;
    EXPECT_EQ(evenOdd(a), 0);
    a = 11;
    EXPECT_EQ(evenOdd(a), 1);
    std::cout << "complete" << std::endl;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}