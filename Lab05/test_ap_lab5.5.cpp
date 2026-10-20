#include <gtest/gtest.h>
#define main lab_main
#include "ap_lab5.5.cpp" 
#undef main

// Тест для базового випадку (однозначне число N = 5)
TEST(RecursiveDigitsTest, BaseCaseSingleDigit) {
    int n = 5;

    EXPECT_EQ(sumn(n), 5);   
    EXPECT_EQ(quant(n), 1);  
    EXPECT_EQ(mmax(n), 5);   
    EXPECT_EQ(mmin(n), 5);   
}

// Тест для багатозначного числа N = 582
TEST(RecursiveDigitsTest, MultiDigitNumber) {
    int n = 582;

    EXPECT_EQ(sumn(n), 15);  
    EXPECT_EQ(quant(n), 3);  
    EXPECT_EQ(mmax(n), 8);   
    EXPECT_EQ(mmin(n), 2);   
}

// Тест для числа з нулями N = 1002
TEST(RecursiveDigitsTest, NumberWithZeros) {
    int n = 1002;

    EXPECT_EQ(sumn(n), 3);   
    EXPECT_EQ(quant(n), 4);  
    EXPECT_EQ(mmax(n), 2);   
    EXPECT_EQ(mmin(n), 0);   
}

// Тест для числа з однаковими цифрами N = 777
TEST(RecursiveDigitsTest, IdenticalDigits) {
    int n = 777;

    EXPECT_EQ(sumn(n), 21);
    EXPECT_EQ(quant(n), 3);
    EXPECT_EQ(mmax(n), 7);
    EXPECT_EQ(mmin(n), 7);
}