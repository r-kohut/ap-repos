#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab6.1.rec.cpp" 
#undef main

// Тест рекурсивної функції Sum (перевірка обчислення суми від'ємних парних елементів)
TEST(RecursiveArrayTest, SumNegativeEvenElements) {
    int arr[] = {-4, -3, 2, -6, 0, 5, -8, -1};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Від'ємні парні: -4 + (-6) + (-8) = -18
    EXPECT_EQ(Sum(arr, size, 0, 0), -18);
}

// Тест рекурсивної функції Quant (перевірка обчислення кількості від'ємних парних елементів)
TEST(RecursiveArrayTest, QuantNegativeEvenElements) {
    int arr[] = {-4, -3, 2, -6, 0, 5, -8, -1};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Від'ємні парні: -4, -6, -8 -> всього 3 елементи
    EXPECT_EQ(Quant(arr, size, 0, 0), 3);
}

// Тест рекурсивної функції Zero (перевірка заміни від'ємних парних елементів на 0)
TEST(RecursiveArrayTest, ZeroNegativeEvenElements) {
    int arr[] = {-4, -3, 2, -6, 0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {0, -3, 2, 0, 0};

    Zero(arr, size, 0);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], expected[i]);
    }
}

// Тест рекурсивної функції Create (перевірка генерації значень у заданому діапазоні)
TEST(RecursiveArrayTest, CreateValueRange) {
    const int size = 50;
    int arr[size];
    const int Low = -20;
    const int High = 34;

    Create(arr, size, Low, High, 0);

    for (int i = 0; i < size; ++i) {
        EXPECT_GE(arr[i], Low);
        EXPECT_LE(arr[i], High);
    }
}

// Тест граничного випадку: відсутність від'ємних парних елементів у масиві
TEST(RecursiveArrayTest, NoNegativeEvenElements) {
    int arr[] = {1, 3, 5, -1, -3, 0};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Sum(arr, size, 0, 0), 0);
    EXPECT_EQ(Quant(arr, size, 0, 0), 0);
}