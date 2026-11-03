#include <gtest/gtest.h>
#define main lab_main
#include "ap_lab.7.1.rec.cpp" 
#undef main

// Допоміжна функція для виділення пам'яті під 2D масив
int** CreateTestMatrix(int rows, int cols) {
    int** a = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        a[i] = new int[cols];
    }
    return a;
}

// Допоміжна функція для звільнення пам'яті 2D масиву
void FreeTestMatrix(int** a, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

// 1. Тест рекурсивних функцій CalcRows та CalcRow (обчислення суми, кількості та заміни елементів)
TEST(RecursiveMatrixTest, CalcRowsOperation) {
    const int rows = 2;
    const int cols = 3;
    int** a = CreateTestMatrix(rows, cols);

    // Вхідна матриця:
    // [ 3, -2, -3]  -> 3 (>0), -2 (парне від'ємне, пропускається), -3 (непарне від'ємне)
    // [-4,  0,  5]  -> -4 (парне від'ємне, пропускається), 0 (пропускається), 5 (>0)
    a[0][0] = 3;  a[0][1] = -2; a[0][2] = -3;
    a[1][0] = -4; a[1][1] = 0;  a[1][2] = 5;

    int S = 0, k = 0;
    CalcRows(a, rows, cols, 0, S, k);

    // Очікувана сума: 3 + (-3) + 5 = 5
    EXPECT_EQ(S, 5);
    // Очікувана кількість відповідних елементів: 3
    EXPECT_EQ(k, 3);

    // Перевірка заміни обчислених елементів на 0
    EXPECT_EQ(a[0][0], 0);
    EXPECT_EQ(a[0][1], -2);
    EXPECT_EQ(a[0][2], 0);
    EXPECT_EQ(a[1][0], -4);
    EXPECT_EQ(a[1][1], 0);
    EXPECT_EQ(a[1][2], 0);

    FreeTestMatrix(a, rows);
}

// 2. Тест рекурсивних функцій Sort та SortPass (сортування стовпчиків за спаданням)
TEST(RecursiveMatrixTest, SortColumnsDescending) {
    const int rows = 3;
    const int cols = 3;
    int** a = CreateTestMatrix(rows, cols);

    // Початкова матриця:
    // Стовпчик 0: [10, 5, 3]
    // Стовпчик 1: [20, 1, 3]
    // Стовпчик 2: [10, 8, 3]
    a[0][0] = 10; a[0][1] = 20; a[0][2] = 10;
    a[1][0] = 5;  a[1][1] = 1;  a[1][2] = 8;
    a[2][0] = 3;  a[2][1] = 3;  a[2][2] = 3;

    Sort(a, rows, cols, 0);

    // Очікувана матриця після сортування:
    // Стовпчик 0: [20, 1, 3]
    // Стовпчик 1: [10, 8, 3]
    // Стовпчик 2: [10, 5, 3]
    EXPECT_EQ(a[0][0], 20); EXPECT_EQ(a[0][1], 10); EXPECT_EQ(a[0][2], 10);
    EXPECT_EQ(a[1][0], 1);  EXPECT_EQ(a[1][1], 8);  EXPECT_EQ(a[1][2], 5);
    EXPECT_EQ(a[2][0], 3);  EXPECT_EQ(a[2][1], 3);  EXPECT_EQ(a[2][2], 3);

    FreeTestMatrix(a, rows);
}

// 3. Тест рекурсивної функції Change (перевірка перестановки двох стовпчиків)
TEST(RecursiveMatrixTest, ChangeColumns) {
    const int rows = 2;
    const int cols = 2;
    int** a = CreateTestMatrix(rows, cols);

    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    Change(a, 0, 1, rows, 0);

    EXPECT_EQ(a[0][0], 2); EXPECT_EQ(a[0][1], 1);
    EXPECT_EQ(a[1][0], 4); EXPECT_EQ(a[1][1], 3);

    FreeTestMatrix(a, rows);
}