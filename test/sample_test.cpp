#include <gtest/gtest.h>
#include "sample.hpp"
#include <iostream>


TEST (sample_test, sample_test) {
    EXPECT_EQ(tryDB(), true);
    //connectDB();
    std::cout << "complete" << std::endl;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}