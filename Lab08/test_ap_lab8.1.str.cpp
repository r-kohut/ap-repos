#include <gtest/gtest.h>
#include <string>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab8.1.str.cpp" 
#undef main

// 1. Тест функції Contains (перевірка наявності підрядка "***")
TEST(StringOperationsTest, ContainsCheck) {
    EXPECT_TRUE(Contains("abc***def"));
    EXPECT_FALSE(Contains("abc**def"));
}

// 2. Тест функції Change (перевірка заміни "***" на "!!!" для одного та декількох входжень)
TEST(StringOperationsTest, ChangeOccurrences) {
    std::string str = "***abc***def";
    std::string result = Change(str);

    EXPECT_EQ(result, "!!!abc!!!def");
    EXPECT_EQ(str, "!!!abc!!!def"); // перевірка зміни рядка за посиланням
}

// 3. Тест функції Change для рядка без підрядка "***" (граничний випадок)
TEST(StringOperationsTest, ChangeNoOccurrences) {
    std::string str = "hello world";
    std::string result = Change(str);

    EXPECT_EQ(result, "hello world");
    EXPECT_EQ(str, "hello world");
}