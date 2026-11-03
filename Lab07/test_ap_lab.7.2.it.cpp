#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab.7.2.it.cpp" 
#undef main

// Допоміжна функція для виділення пам'яті під 2D масив (k рядків, n стовпчиків)
int** CreateTestMatrix(int k, int n) {
    int** a = new int*[k];
    for (int i = 0; i < k; ++i) {
        a[i] = new int[n];
    }
    return a;
}

// Допоміжна функція для звільнення пам'яті 2D масиву
void FreeTestMatrix(int** a, int k) {
    for (int i = 0; i < k; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

// 1. Тест функцій MinInRow та MaxInRow (пошук індексів мін. та макс. елементів у рядку)
TEST(MatrixTest, MinAndMaxInRow) {
    const int k = 2; // кількість рядків
    const int n = 4; // кількість стовпчиків
    int** a = CreateTestMatrix(k, n);

    // Рядок 0: [5, 12, -3, 8]  -> Min: -3 (індекс 2), Max: 12 (індекс 1)
    a[0][0] = 5; a[0][1] = 12; a[0][2] = -3; a[0][3] = 8;
    // Рядок 1: [-10, 0, 15, -2] -> Min: -10 (індекс 0), Max: 15 (індекс 2)
    a[1][0] = -10; a[1][1] = 0; a[1][2] = 15; a[1][3] = -2;

    EXPECT_EQ(MinInRow(a, 0, n), 2);
    EXPECT_EQ(MaxInRow(a, 0, n), 1);

    EXPECT_EQ(MinInRow(a, 1, n), 0);
    EXPECT_EQ(MaxInRow(a, 1, n), 2);

    FreeTestMatrix(a, k);
}

// 2. Тест функції Change (перевірка перестановки двох елементів у рядку)
TEST(MatrixTest, ChangeElements) {
    const int k = 1;
    const int n = 3;
    int** a = CreateTestMatrix(k, n);

    a[0][0] = 10; a[0][1] = 20; a[0][2] = 30;

    // Міняємо місцями елементи на індексах 0 та 2 у рядку 0
    Change(a, 0, 0, 2);

    EXPECT_EQ(a[0][0], 30);
    EXPECT_EQ(a[0][1], 20);
    EXPECT_EQ(a[0][2], 10);

    FreeTestMatrix(a, k);
}
