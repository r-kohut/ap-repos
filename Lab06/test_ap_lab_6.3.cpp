#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab_6.3.it.cpp" 
#undef main

// Тест граничного випадку: відсутність парних елементів масиву
TEST(ArrayTest, NoEvenElements) {
    int arr[] = {1, 3, 5, -1, -3, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Quant(arr, size), 0);
}

// Тест граничного випадку: усі елементи масиву є парними
TEST(ArrayTest, AllEvenElements) {
    int arr[] = {-2, 4, 0, -8, 10};
    const int size = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(Quant(arr, size), 5);
}