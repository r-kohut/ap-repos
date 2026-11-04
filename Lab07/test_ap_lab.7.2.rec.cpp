#include <gtest/gtest.h>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "ap_lab.7.2.rec.cpp" 
#undef main

// Допоміжна функція для виділення пам'яті під 2D масив (rowCount рядків, colCount стовпців)
int** CreateTestMatrix(int rowCount, int colCount) {
    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        a[i] = new int[colCount];
    }
    return a;
}

// Допоміжна функція для звільнення пам'яті 2D масиву
void FreeTestMatrix(int** a, int rowCount) {
    for (int i = 0; i < rowCount; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

// 1. Тест рекурсивних функцій пошуку індексів min і max елементів в рядку (SearchMinColRow, SearchMaxColRow)
TEST(RecursiveMatrixTest, SearchMinMaxColRow) {
    const int rowCount = 2;
    const int colCount = 4;
    int** a = CreateTestMatrix(rowCount, colCount);

    // Рядок 0: [5, 12, -3, 8]  -> Min: -3 (індекс 2), Max: 12 (індекс 1)
    a[0][0] = 5; a[0][1] = 12; a[0][2] = -3; a[0][3] = 8;
    // Рядок 1: [-10, 0, 15, -2] -> Min: -10 (індекс 0), Max: 15 (індекс 2)
    a[1][0] = -10; a[1][1] = 0; a[1][2] = 15; a[1][3] = -2;

    int minCol0 = 0, maxCol0 = 0;
    SearchMinColRow(a, 0, colCount, 0, minCol0);
    SearchMaxColRow(a, 0, colCount, 0, maxCol0);
    EXPECT_EQ(minCol0, 2);
    EXPECT_EQ(maxCol0, 1);

    int minCol1 = 0, maxCol1 = 0;
    SearchMinColRow(a, 1, colCount, 0, minCol1);
    SearchMaxColRow(a, 1, colCount, 0, maxCol1);
    EXPECT_EQ(minCol1, 0);
    EXPECT_EQ(maxCol1, 2);

    FreeTestMatrix(a, rowCount);
}

// 2. Тест рекурсивного обміну min та max у рядках з кроком 2 (SwapMinMaxEvenRows)
TEST(RecursiveMatrixTest, SwapMinMaxEvenRowsOperation) {
    const int rowCount = 3;
    const int colCount = 4;
    int** a = CreateTestMatrix(rowCount, colCount);

    // Рядок 0 (не змінюється): [1, 2, 3, 4]
    a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;

    // Рядок 1 (обробляється, rowNo=1): [10, -5, 20, 3] -> Min: -5 (індекс 1), Max: 20 (індекс 2)
    a[1][0] = 10; a[1][1] = -5; a[1][2] = 20; a[1][3] = 3;

    // Рядок 2 (пропускається): [5, 6, 7, 8]
    a[2][0] = 5; a[2][1] = 6; a[2][2] = 7; a[2][3] = 8;

    // Виклик з rowNo = 1
    SwapMinMaxEvenRows(a, rowCount, colCount, 1);

    // Рядок 0 залишився без змін
    EXPECT_EQ(a[0][0], 1); EXPECT_EQ(a[0][1], 2); EXPECT_EQ(a[0][2], 3); EXPECT_EQ(a[0][3], 4);

    // У рядку 1 елементи -5 та 20 помінялися місцями
    EXPECT_EQ(a[1][0], 10);
    EXPECT_EQ(a[1][1], 20); // Тепер Max на місці Min
    EXPECT_EQ(a[1][2], -5); // Тепер Min на місці Max
    EXPECT_EQ(a[1][3], 3);

    // Рядок 2 залишився без змін
    EXPECT_EQ(a[2][0], 5); EXPECT_EQ(a[2][1], 6); EXPECT_EQ(a[2][2], 7); EXPECT_EQ(a[2][3], 8);

    FreeTestMatrix(a, rowCount);
}