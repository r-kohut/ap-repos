#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab.6.2.rec.cpp" 
#undef main

// Тест рекурсивної функції Max (пошук максимального елемента масиву)
TEST(RecursiveArrayTest, MaxElement) {
    int arr[] = {-10, 5, 23, -18, 0, 14, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Max(arr, size, 1, arr[0]), 23);
}

// Тест рекурсивної функції Min (пошук мінімального елемента масиву)
TEST(RecursiveArrayTest, MinElement) {
    int arr[] = {-10, 5, 23, -18, 0, 14, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Min(arr, size, 1, arr[0]), -18);
}

// Тест функції Sum (перевірка суми максимального та мінімального елементів)
TEST(RecursiveArrayTest, SumMaxMin) {
    int arr[] = {-10, 5, 23, -18, 0, 14, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Max = 23, Min = -18, Sum = 23 + (-18) = 5
    EXPECT_EQ(Sum(arr, size), 5);
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

// Тест граничного випадку: масив з однаковими елементами
TEST(RecursiveArrayTest, SameElements) {
    int arr[] = {7, 7, 7, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Max(arr, size, 1, arr[0]), 7);
    EXPECT_EQ(Min(arr, size, 1, arr[0]), 7);
    EXPECT_EQ(Sum(arr, size), 14);
}