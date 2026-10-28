#include <gtest/gtest.h>
#define main lab_main
#include "ap_lab6.4.rec.cpp" 
#undef main

// Тест рекурсивної функції CountGreaterC (перевірка кількості елементів, більших за C)
TEST(RecursiveDoubleArrayTest, CountGreaterC) {
    double arr[] = {-2.5, 3.1, 0.0, 5.5, -1.2, 4.0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    double C = 2.0;

    // Елементи > 2.0: 3.1, 5.5, 4.0 всього 3
    EXPECT_EQ(CountGreaterC(arr, size, C, 0), 3);
}

// Тест рекурсивних функцій MaxAbs та MultAfterMax (пошук max за модулем та обчислення добутку після нього)
TEST(RecursiveDoubleArrayTest, MaxAbsAndMultAfterMax) {
    double arr[] = {1.0, -8.0, 2.0, -3.0, 4.0};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Максимальний за модулем: |-8.0| = 8.0 (індекс 1)
    int iMax = MaxAbs(arr, size, 1, 0);
    EXPECT_EQ(iMax, 1);

    // Елементи після iMax (з індексу 2): 2.0 * (-3.0) * 4.0 = -24.0
    EXPECT_DOUBLE_EQ(MultAfterMax(arr, size, iMax + 1), -24.0);
}

// Тест рекурсивної функції Replace (перевірка переміщення від'ємних елементів на початок масиву)
TEST(RecursiveDoubleArrayTest, ReplaceNegativeElementsFirst) {
    double arr[] = {1.5, -2.0, 3.0, -4.5, 0.0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    double expected[] = {-2.0, -4.5, 1.5, 3.0, 0.0};

    Replace(arr, size, 0, 0);

    for (int i = 0; i < size; ++i) {
        EXPECT_DOUBLE_EQ(arr[i], expected[i]);
    }
}