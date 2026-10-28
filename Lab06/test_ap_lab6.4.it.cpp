#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab.6.4.it.cpp" 
#undef main

//Тест функції CountGreaterC (перевірка кількості елементів, більших за C)
TEST(DoubleArrayTest, CountGreaterC) {
    double arr[] = {-2.5, 3.1, 0.0, 5.5, -1.2, 4.0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    double C = 2.0;

    // Елементи > 2.0: 3.1, 5.5, 4.0  всього 3
    EXPECT_EQ(CountGreaterC(arr, size, C), 3);
}

// Тест функції MultAfterMax для граничного випадку (максимальний елемент є останнім)
TEST(DoubleArrayTest, MultAfterMaxWhenLastElement) {
    double arr[] = {1.0, 2.0, -3.0, 10.5};
    const int size = sizeof(arr) / sizeof(arr[0]);
    int iMax = MaxAbs(arr, size); // iMax = 3 (останній)

    // Після останнього елемента елементів немає, результат має бути 1.0
    EXPECT_DOUBLE_EQ(MultAfterMax(arr, size, iMax), 1.0);
}

// Тест граничного випадку для Replace: масив без від'ємних елементів
TEST(DoubleArrayTest, ReplaceNoNegatives) {
    double arr[] = {1.0, 2.5, 0.0, 4.2};
    const int size = sizeof(arr) / sizeof(arr[0]);
    double expected[] = {1.0, 2.5, 0.0, 4.2};

    Replace(arr, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_DOUBLE_EQ(arr[i], expected[i]);
    }
}