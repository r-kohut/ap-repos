#include <gtest/gtest.h>

// Include the lab source with main() renamed, so the lab file stays unchanged
#define main lab_main
#include "ap_lab_5.3.cpp"
#undef main



// Тест для першої гілки: коли |x| >= 1
TEST(ZFunctionTest, BranchGreaterOrEqualOne) {
    // Перевірка межі x = 1.0
    double x1 = 1.0;
    double expected1 = (cos(2 * x1) + 1.0) / (cos(x1) + (sin(x1) * sin(x1)));
    EXPECT_DOUBLE_EQ(z(x1), expected1);

    // Перевірка x = 2.5
    double x2 = 2.5;
    double expected2 = (cos(2 * x2) + 1.0) / (cos(x2) + (sin(x2) * sin(x2)));
    EXPECT_DOUBLE_EQ(z(x2), expected2);
}

// Тест для другої гілки: коли |x| < 1 (цикл)
TEST(ZFunctionTest, BranchLessThanOne) {
    // Перевірка для x = 0.0 (за логікою циклу результат має бути 0)
    EXPECT_DOUBLE_EQ(z(0.0), 0.0);
}