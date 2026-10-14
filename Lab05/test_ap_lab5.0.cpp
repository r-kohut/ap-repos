#include <gtest/gtest.h>

// Include the lab source with main() renamed, so the lab file stays unchanged
#define main lab_main
#include "ap_lab5.0.cpp"
#undef main

// Тест для додатних чисел
TEST(SumFunctionTest, HandlesPositiveInput) {
    EXPECT_EQ(sum(2, 3), 5);
    EXPECT_EQ(sum(10, 25), 35);
}

    