#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab.7.1.it.cpp" 
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

// 3. Тест функції Change (перевірка перестановки двох стовпчиків)
TEST(MatrixTest, ChangeColumns) {
    const int rows = 2;
    const int cols = 2;
    int** a = CreateTestMatrix(rows, cols);

    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    Change(a, 0, 1, rows);

    EXPECT_EQ(a[0][0], 2); EXPECT_EQ(a[0][1], 1);
    EXPECT_EQ(a[1][0], 4); EXPECT_EQ(a[1][1], 3);

    FreeTestMatrix(a, rows);
}

// 4. Тест функції Create (перевірка відповідності діапазону значень [Low, High])
TEST(MatrixTest, CreateValueRange) {
    const int rows = 8;
    const int cols = 6;
    const int Low = -34;
    const int High = 26;
    int** a = CreateTestMatrix(rows, cols);

    Create(a, rows, cols, Low, High);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_GE(a[i][j], Low);
            EXPECT_LE(a[i][j], High);
        }
    }

    FreeTestMatrix(a, rows);
}