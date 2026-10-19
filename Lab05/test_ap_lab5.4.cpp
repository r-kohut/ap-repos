#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab5.4.cpp" 
#undef main

// Тест для граничного значення N = 1 (обчислення точного  значення cos(1))
TEST(SeriesTest, BaseCaseNEqualsOne) {
    int N = 1;
    double expected = cos(1.0); // при N=1: (1*1)/(1*1) * cos((1*1)/(1*1)) = cos(1)

    EXPECT_NEAR(S0(N), expected, 0.0000001);
    EXPECT_NEAR(S1(N, 1), expected, 0.0000001);
    EXPECT_NEAR(S2(N, N), expected, 0.0000001);
    EXPECT_NEAR(S3(N, 1, 1.0), expected, 0.0000001);
    EXPECT_NEAR(S4(N, N, 1.0), expected, 0.0000001);
}

// Тест порівняння всіх 4-х рекурсивних методів із ітераційним (S0) для N = 3
TEST(SeriesTest, CompareRecursiveWithIterative) {
    int N = 3;
    double expected = S0(N);

    EXPECT_NEAR(S1(N, 1), expected, 0.0000001);
    EXPECT_NEAR(S2(N, N), expected, 0.0000001);
    EXPECT_NEAR(S3(N, 1, 1.0), expected, 0.0000001);
    EXPECT_NEAR(S4(N, N, 1.0), expected, 0.0000001);
}

// Окремий тест для перевірки ітераційної функції S0
TEST(SeriesTest, IterativeMethodS0) {
    int N = 2;
    double expected = ((1.0 / 4.0) * cos(4.0)) * (1.0 * cos(1.0));
    EXPECT_NEAR(S0(N), expected, 0.0000001);
}