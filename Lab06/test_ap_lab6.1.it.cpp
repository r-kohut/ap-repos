#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab.6.1.it.cpp" 
#undef main

// Тест для функції Sum (перевірка обчислення суми від'ємних парних елементів)
TEST(ArrayTest, SumNegativeEvenElements) {
    int arr[] = {-4, -3, 2, -6, 0, 5, -8, -1};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Від'ємні парні: -4 + (-6) + (-8) = -18
    EXPECT_EQ(Sum(arr, size), -18);
}

// Тест для функції Quant (перевірка обчислення кількості від'ємних парних елементів)
TEST(ArrayTest, QuantNegativeEvenElements) {
    int arr[] = {-4, -3, 2, -6, 0, 5, -8, -1};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Від'ємні парні: -4, -6, -8 -> всього 3 елементи
    EXPECT_EQ(Quant(arr, size), 3);
}

// Тест для функції Zero (перевірка заміни від'ємних парних елементів на 0)
TEST(ArrayTest, ZeroNegativeEvenElements) {
    int arr[] = {-4, -3, 2, -6, 0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {0, -3, 2, 0, 0};

    Zero(arr, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], expected[i]);
    }
}

// Тест для функції Create (перевірка належності згенерованих елементів заданому діапазону)
TEST(ArrayTest, CreateValueRange) {
    const int size = 50;
    int arr[size];
    const int Low = -20;
    const int High = 34;

    Create(arr, size, Low, High);

    for (int i = 0; i < size; ++i) {
        EXPECT_GE(arr[i], Low);
        EXPECT_LE(arr[i], High);
    }
}

// Тест граничного випадку: відсутність від'ємних парних елементів у масиві
TEST(ArrayTest, NoNegativeEvenElements) {
    int arr[] = {1, 3, 5, -1, -3, 0};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Sum(arr, size), 0);
    EXPECT_EQ(Quant(arr, size), 0);
}