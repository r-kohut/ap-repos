#include <gtest/gtest.h>

// Include the lab source with main() renamed, so the lab file stays unchanged
#define main lab_main
#include "ap_lab5.1.cpp"
#undef main

// Test case 1: Test with zeros
TEST(HFunctionTest, HandlesZeros) {
    // Expected: (0 + 0 + 0) / (1 + 0 + 0) = 0
    EXPECT_DOUBLE_EQ( h(0.0, 0.0), 0.0 );
}