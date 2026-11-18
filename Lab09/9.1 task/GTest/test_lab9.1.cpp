// test_9_1.cpp
// Unit-тести для лабораторної роботи 9.1 (варіант 15): sin(x)/x = сума (-1)^n * x^(2n) / (2n+1)!
// Файл Lab_9_1.cpp з main() у збірку тестів НЕ входить: main надає gtest_main.

#include <gtest/gtest.h>
#include <cmath>

#include "../var.h"
#include "../dod.h"
#include "../sum.h"

// допоміжна функція: задає x і точність, рахує суму ряду, повертає її
static double Series(double x, double eps)
{
    nsVar::x = x;
    nsVar::e = eps;
    nsSum::sum();
    return nsVar::s;
}

// 1. dod(): множення поточного доданка на -x^2 / (2n(2n+1)), n = 1, x = 1
TEST(SeriesTest, DodFirstStep) {
    nsVar::x = 1.0;
    nsVar::n = 1;
    nsVar::a = 1.0;
    nsDod::dod();
    EXPECT_NEAR(nsVar::a, -1.0 / 6.0, 1e-12);
}

// 2. dod(): другий крок, n = 2, x = 2 (множник -4 / 20 = -0.2)
TEST(SeriesTest, DodSecondStep) {
    nsVar::x = 2.0;
    nsVar::n = 2;
    nsVar::a = 1.0;
    nsDod::dod();
    EXPECT_NEAR(nsVar::a, -0.2, 1e-12);
}

// 3. Граничний випадок x = 0: перший доданок 1, решта нулі, сума = 1
TEST(SeriesTest, SumAtZero) {
    EXPECT_DOUBLE_EQ(Series(0.0, 0.0001), 1.0);
}

// 4. Сума ряду збігається з sin(x)/x у точці x = 1
TEST(SeriesTest, SumMatchesSinAtOne) {
    EXPECT_NEAR(Series(1.0, 1e-6), std::sin(1.0) / 1.0, 1e-5);
}

// 5. Сума ряду збігається з sin(x)/x у точці x = 3
TEST(SeriesTest, SumMatchesSinAtThree) {
    EXPECT_NEAR(Series(3.0, 1e-8), std::sin(3.0) / 3.0, 1e-7);
}

// 6. Функція парна: у ряді лише x^2, тому S(-x) = S(x)
TEST(SeriesTest, SeriesIsEven) {
    double positive = Series(2.0, 1e-6);
    double negative = Series(-2.0, 1e-6);
    EXPECT_DOUBLE_EQ(positive, negative);
}

// 7. Менша точність дає не менше доданків
TEST(SeriesTest, SmallerEpsMoreTerms) {
    Series(2.0, 1e-2);
    int fewTerms = nsVar::n;
    Series(2.0, 1e-8);
    int manyTerms = nsVar::n;
    EXPECT_GE(manyTerms, fewTerms);
}