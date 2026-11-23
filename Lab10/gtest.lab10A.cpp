#include <gtest/gtest.h>
#include <string>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "lab10A.cpp"
#undef main

// 1. Тест функції Average (цілий результат)
TEST(StudentOperationsTest, AverageInteger) {
    Student st = { "Ivanenko", 1, KOMP_NAUKY, 5, 4, 3 };
    EXPECT_NEAR(Average(st), 4.0, 1e-9);
}

// 2. Тест функції Average (дробовий результат)
TEST(StudentOperationsTest, AverageFractional) {
    Student st = { "Petrenko", 2, INFORMATYKA, 5, 5, 4 };
    EXPECT_NEAR(Average(st), 14.0 / 3.0, 1e-9);
}

// 3. Тест функції AverageMax (максимум посередині масиву)
TEST(StudentOperationsTest, AverageMaxInTheMiddle) {
    Student s[3] = {
        { "A", 1, KOMP_NAUKY,    3, 3, 3 },   // 3.00
        { "B", 1, INFORMATYKA,   5, 5, 4 },   // 4.67
        { "C", 1, MATEMTAEKONOM, 4, 4, 4 }    // 4.00
    };
    EXPECT_NEAR(AverageMax(s, 3), 14.0 / 3.0, 1e-9);
}

// 4. Тест функції AverageMax (граничні випадки: максимум першим та останнім)
TEST(StudentOperationsTest, AverageMaxFirstAndLast) {
    Student first[2] = {
        { "A", 1, KOMP_NAUKY,         5, 5, 5 },   // 5.00
        { "B", 1, TRUDOVE_NAVCHANNYA, 2, 2, 2 }    // 2.00
    };
    EXPECT_NEAR(AverageMax(first, 2), 5.0, 1e-9);

    Student last[2] = {
        { "A", 1, KOMP_NAUKY,         3, 3, 3 },   // 3.00
        { "B", 1, FIZYKA_INFORMATYKA, 4, 5, 5 }    // 4.67
    };
    EXPECT_NEAR(AverageMax(last, 2), 14.0 / 3.0, 1e-9);
}

// 5. Тест функції AverageMax (один студент)
TEST(StudentOperationsTest, AverageMaxSingleStudent) {
    Student s[1] = { { "A", 1, KOMP_NAUKY, 4, 4, 4 } };
    EXPECT_NEAR(AverageMax(s, 1), 4.0, 1e-9);
}

// 6. Тест функції PercentFizyka4or5 (частина студентів)
TEST(StudentOperationsTest, PercentFizykaHalf) {
    Student s[4] = {
        { "A", 1, KOMP_NAUKY,         5, 3, 3 },   // фізика 5, враховується
        { "B", 1, INFORMATYKA,        4, 4, 4 },   // фізика 4, враховується
        { "C", 1, MATEMTAEKONOM,      3, 5, 5 },   // фізика 3, ні
        { "D", 1, TRUDOVE_NAVCHANNYA, 2, 2, 2 }    // фізика 2, ні
    };
    EXPECT_DOUBLE_EQ(PercentFizyka4or5(s, 4), 50.0);
}

// 7. Тест функції PercentFizyka4or5 (граничні випадки: нікого немає, всі)
TEST(StudentOperationsTest, PercentFizykaNoneAndAll) {
    Student none[2] = {
        { "A", 1, KOMP_NAUKY,  3, 5, 5 },
        { "B", 1, INFORMATYKA, 2, 4, 4 }
    };
    EXPECT_DOUBLE_EQ(PercentFizyka4or5(none, 2), 0.0);

    Student all[3] = {
        { "A", 1, KOMP_NAUKY,         5, 3, 3 },
        { "B", 1, INFORMATYKA,        4, 3, 3 },
        { "C", 1, FIZYKA_INFORMATYKA, 5, 3, 3 }
    };
    EXPECT_DOUBLE_EQ(PercentFizyka4or5(all, 3), 100.0);
}

// 8. Тест функції PercentFizyka4or5 (дробовий процент)
TEST(StudentOperationsTest, PercentFizykaOneOfThree) {
    Student s[3] = {
        { "A", 1, KOMP_NAUKY,  5, 3, 3 },
        { "B", 1, INFORMATYKA, 3, 3, 3 },
        { "C", 1, INFORMATYKA, 2, 3, 3 }
    };
    EXPECT_NEAR(PercentFizyka4or5(s, 3), 100.0 / 3.0, 1e-9);
}