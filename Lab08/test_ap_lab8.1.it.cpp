#include <gtest/gtest.h>
#include <cstring>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab8.1.it.cpp" 
#undef main

// 1. Тест функції Contains (перевірка наявності підрядка "***" у C-рядку)
TEST(CStringOperationsTest, ContainsCheck) {
    EXPECT_TRUE(Contains("abc***def"));
    EXPECT_FALSE(Contains("abc**def"));
    EXPECT_FALSE(Contains("hello world"));
}

// 2. Тест функції Change (перевірка заміни "***" на "!!" для одного та декількох входжень)
TEST(CStringOperationsTest, ChangeOccurrences) {
    char str[100] = "***abc***def";
    char* dest = Change(str);

    EXPECT_STREQ(dest, "!!abc!!def");
    EXPECT_STREQ(str, "!!abc!!def"); // перевірка зміни вихідного буфера через strcpy

    delete[] dest; // звільнення виділеної пам'яті у функції Change
}

// 3. Тест функції Change для рядка без підрядка "***" (граничний випадок)
TEST(CStringOperationsTest, ChangeNoOccurrences) {
    char str[100] = "hello world";
    char* dest = Change(str);

    EXPECT_STREQ(dest, "hello world");
    EXPECT_STREQ(str, "hello world");

    delete[] dest; // звільнення виділеної пам'яті
}