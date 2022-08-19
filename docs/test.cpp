#include "gtest/gtest.h"

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    EXPECT_EQ(1, 2);
}