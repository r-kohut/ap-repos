#include <gtest/gtest.h>

#define main lab_main
#include "ap_lab6.3.rec.cpp" 
#undef main


//Тест шаблонної функції Quant для типу int
TEST(RecursiveQuantTest, TemplateQuantInt) {
    int arr[] = {10, 15, 22, 33, 44, 55};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Парні елементи: 10, 22, 44 (усього 3)
    EXPECT_EQ(Quant<int>(arr, size, 0), 3);
}

//Тест шаблонної функції Quant для типу long long
TEST(RecursiveQuantTest, TemplateQuantLongLong) {
    long long arr[] = {2LL, 3LL, 4LL, 7LL, 10LL, 12LL};
    const int size = sizeof(arr) / sizeof(arr[0]);

    // Парні елементи: 2, 4, 10, 12 (усього 4)
    EXPECT_EQ(Quant<long long>(arr, size, 0), 4);
}



// масив лише з непарними чи лише з парними елементами
TEST(RecursiveQuantTest, EdgeCasesAllOrNone) {
    int allOdd[] = {1, 3, 5, 7, -9, -11};
    const int sizeOdd = sizeof(allOdd) / sizeof(allOdd[0]);
    EXPECT_EQ(Quant(allOdd, sizeOdd, 0), 0);

    int allEven[] = {-4, -2, 0, 2, 4, 6};
    const int sizeEven = sizeof(allEven) / sizeof(allEven[0]);
    EXPECT_EQ(Quant(allEven, sizeEven, 0), 6);
}

//масив з одного елемента
TEST(RecursiveQuantTest, SingleElementArray) {
    int evenSingle[] = {4};
    EXPECT_EQ(Quant(evenSingle, 1, 0), 1);

    int oddSingle[] = {7};
    EXPECT_EQ(Quant(oddSingle, 1, 0), 0);
}

