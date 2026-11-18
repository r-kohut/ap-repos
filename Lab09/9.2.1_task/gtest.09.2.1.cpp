#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "lab09.2.1.cpp"
#undef main

// допоміжна функція: подає x, y на вхід lab_main() і повертає все, що вона вивела
static std::string RunMain(double x, double y)
{
    std::istringstream in(std::to_string(x) + " " + std::to_string(y));
    std::streambuf* oldIn = std::cin.rdbuf(in.rdbuf());
    testing::internal::CaptureStdout();
    lab_main();
    std::string out = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(oldIn);
    return out;
}

// 1. Макрос SQR: коректно працює з виразом (дужки навколо параметра)
TEST(MacroTest, Sqr) {
    EXPECT_DOUBLE_EQ(SQR(3), 9);
    EXPECT_DOUBLE_EQ(SQR(-4), 16);
    EXPECT_DOUBLE_EQ(SQR(1 + 2), 9);     // без дужок вийшло б 1 + 2*1 + 2 = 5
}

// 2. Макрос ABS: від'ємне, додатне, нуль
TEST(MacroTest, Abs) {
    EXPECT_DOUBLE_EQ(ABS(-5.5), 5.5);
    EXPECT_DOUBLE_EQ(ABS(5.5), 5.5);
    EXPECT_DOUBLE_EQ(ABS(0), 0);
}

// 3. Макрос MAX
TEST(MacroTest, Max) {
    EXPECT_DOUBLE_EQ(MAX(2, 7), 7);
    EXPECT_DOUBLE_EQ(MAX(7, 2), 7);
    EXPECT_DOUBLE_EQ(MAX(-3, -8), -3);
}

// 4. Макрос MIN
TEST(MacroTest, Min) {
    EXPECT_DOUBLE_EQ(MIN(2, 7), 2);
    EXPECT_DOUBLE_EQ(MIN(7, 2), 2);
    EXPECT_DOUBLE_EQ(MIN(-3, -8), -8);
}

// 5. Вкладені макроси (як у виразі варіанта 15)
TEST(MacroTest, Nested) {
    double x = 5, y = 1;
    EXPECT_DOUBLE_EQ(MIN(SQR(x - y), ABS(y - x)), 4);    // min(16, 4)
}

// 6. Макрос PRINT виводить ім'я виразу та його значення
TEST(MacroTest, Print) {
    int w = 42;
    testing::internal::CaptureStdout();
    PRINT(w);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "w = 42\n");
}

// 7. Гілка z = 1: x = 5, y = 1 -> min(16, 4) = 4
//    Гілка z != 1 (Z = 2): x = 1, y = 3 -> max(1 + 9, 2 + 1) = 10
TEST(BranchTest, ResultByZ) {
#if Z == 1
    std::string out = RunMain(5, 1);
    EXPECT_NE(out.find("branch: z = 1"), std::string::npos);
    EXPECT_NE(out.find("w = 4\n"), std::string::npos);
#else
    std::string out = RunMain(1, 3);
    EXPECT_NE(out.find("branch: z != 1"), std::string::npos);
    EXPECT_NE(out.find("w = 10\n"), std::string::npos);     // (x + y^2)^2 дало б 100
#endif
}

// 8. Програма виводить введені x та y (control output)
TEST(BranchTest, EchoInput) {
    std::string out = RunMain(2, 3);
    EXPECT_NE(out.find("x = 2\n"), std::string::npos);
    EXPECT_NE(out.find("y = 3\n"), std::string::npos);
}