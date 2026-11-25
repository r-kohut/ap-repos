#include <gtest/gtest.h>
#include <string>

// Підключення вихідного файлу лабораторної роботи з перейменуванням main()
#define main lab_main
#include "lab10.2.B.cpp"
#undef main

// 1. Тест функції SpecToString (усі спеціальності та некоректне значення)
TEST(StudentLab10_2B_Test, SpecToStringAllValues) {
    EXPECT_EQ(SpecToString(KOMP_NAUKY), "Комп'ютерні науки");
    EXPECT_EQ(SpecToString(INFORMATYKA), "Інформатика");
    EXPECT_EQ(SpecToString(MATEMTAEKONOM), "Математика та економіка");
    EXPECT_EQ(SpecToString(FIZYKA_INFORMATYKA), "Фізика та інформатика");
    EXPECT_EQ(SpecToString(TRUDOVE_NAVCHANNYA), "Трудове навчання");
    EXPECT_EQ(SpecToString(static_cast<Spec>(99)), "");
}

// 2. Тест функції Pad (доповнення пробілами для ASCII та кирилиці)
TEST(StudentLab10_2B_Test, PadUtf8AndAscii) {
    EXPECT_EQ(Pad("ABC", 5), "ABC  ");
    EXPECT_EQ(Pad("Іван", 6), "Іван  ");
    EXPECT_EQ(Pad("ДовгийРядок", 5), "ДовгийРядок");
}

// 3. Тест функції ThirdGrade (вибір третьої оцінки з union залежно від спеціальності)
TEST(StudentLab10_2B_Test, ThirdGradeBySpec) {
    Student st1 = { "Ivanenko", 1, KOMP_NAUKY, 4, 4, {5} };
    EXPECT_EQ(ThirdGrade(st1), 5);

    Student st2 = { "Petrenko", 2, INFORMATYKA, 4, 4, {4} };
    EXPECT_EQ(ThirdGrade(st2), 4);

    Student st3 = { "Sydorenko", 3, MATEMTAEKONOM, 4, 4, {3} };
    EXPECT_EQ(ThirdGrade(st3), 3);

    Student st4 = { "Kovalenko", 2, FIZYKA_INFORMATYKA, 4, 4, {5} };
    EXPECT_EQ(ThirdGrade(st4), 5);

    Student st5 = { "Bondarenko", 1, TRUDOVE_NAVCHANNYA, 4, 4, {2} };
    EXPECT_EQ(ThirdGrade(st5), 2);
}

// 4. Тест функції Average (цілий та дробовий результати з урахуванням ThirdGrade)
TEST(StudentLab10_2B_Test, AverageCalculation) {
    Student st1 = { "Ivanenko", 1, KOMP_NAUKY, 5, 4, {3} };
    EXPECT_NEAR(Average(st1), 4.0, 1e-9);

    Student st2 = { "Petrenko", 2, INFORMATYKA, 5, 5, {4} };
    EXPECT_NEAR(Average(st2), 14.0 / 3.0, 1e-9);
}

// 5. Тест функції Compare (усі 3 ключі порівняння: середній бал, математика, прізвище)
TEST(StudentLab10_2B_Test, CompareAllKeys) {
    Student st = { "Kovalenko", 2, INFORMATYKA, 4, 4, {4} }; // avg = 4.0

    // Повний збіг
    EXPECT_EQ(Compare(st, 4.0, 4, "Kovalenko"), 0);

    // Порівняння за середнім балом (допуск 0.005)
    EXPECT_EQ(Compare(st, 4.5, 4, "Kovalenko"), -1);
    EXPECT_EQ(Compare(st, 3.5, 4, "Kovalenko"), 1);

    // Однакові середні бали -> порівняння за оцінкою з математики
    EXPECT_EQ(Compare(st, 4.0, 5, "Kovalenko"), -1);
    EXPECT_EQ(Compare(st, 4.0, 3, "Kovalenko"), 1);

    // Однакові середні бали та математика -> порівняння за прізвищем
    EXPECT_EQ(Compare(st, 4.0, 4, "Petrenko"), -1);
    EXPECT_EQ(Compare(st, 4.0, 4, "Bondarenko"), 1);
}

// 6. Тест фізичного сортування Sort (перевірка багаторівневого ключа та різних спеціальностей)
TEST(StudentLab10_2B_Test, PhysicalSortMultiKey) {
    Student s[5] = {
        { "Petrenko",   1, KOMP_NAUKY,         5, 5, {5} }, // avg 5.00, math 5
        { "Shevchenko", 2, INFORMATYKA,        4, 4, {4} }, // avg 4.00, math 4
        { "Bondarenko", 1, MATEMTAEKONOM,      4, 4, {4} }, // avg 4.00, math 4
        { "Kovalenko",  3, FIZYKA_INFORMATYKA, 3, 5, {4} }, // avg 4.00, math 5
        { "Melnyk",     2, TRUDOVE_NAVCHANNYA, 3, 3, {3} }  // avg 3.00, math 3
    };

    Sort(s, 5);

    // Очікуваний порядок за зростанням:
    // 0: Melnyk (avg 3.00)
    // 1: Bondarenko (avg 4.00, math 4, "Bondarenko")
    // 2: Shevchenko (avg 4.00, math 4, "Shevchenko")
    // 3: Kovalenko (avg 4.00, math 5)
    // 4: Petrenko (avg 5.00)
    EXPECT_EQ(s[0].prizv, "Melnyk");
    EXPECT_EQ(s[1].prizv, "Bondarenko");
    EXPECT_EQ(s[2].prizv, "Shevchenko");
    EXPECT_EQ(s[3].prizv, "Kovalenko");
    EXPECT_EQ(s[4].prizv, "Petrenko");
}

// 7. Тест індексного сортування IndexSort (перевірка збереження вихідного масиву)
TEST(StudentLab10_2B_Test, IndexSortPreservesOriginalArray) {
    Student s[4] = {
        { "Shevchenko", 2, INFORMATYKA,        4, 4, {4} }, // 0: avg 4.00, math 4
        { "Melnyk",     1, TRUDOVE_NAVCHANNYA, 3, 3, {3} }, // 1: avg 3.00, math 3
        { "Bondarenko", 1, MATEMTAEKONOM,      4, 4, {4} }, // 2: avg 4.00, math 4
        { "Petrenko",   3, KOMP_NAUKY,         5, 5, {5} }  // 3: avg 5.00, math 5
    };

    int* I = IndexSort(s, 4);

    // Вихідний масив не змінився
    EXPECT_EQ(s[0].prizv, "Shevchenko");
    EXPECT_EQ(s[1].prizv, "Melnyk");
    EXPECT_EQ(s[2].prizv, "Bondarenko");
    EXPECT_EQ(s[3].prizv, "Petrenko");

    // Індексний масив вказує на правильний порядок: 1 -> 2 -> 0 -> 3
    EXPECT_EQ(I[0], 1);
    EXPECT_EQ(I[1], 2);
    EXPECT_EQ(I[2], 0);
    EXPECT_EQ(I[3], 3);

    delete[] I;
}

// 8. Тест бінарного пошуку у фізично впорядкованому масиві (BinSearch)
TEST(StudentLab10_2B_Test, BinSearchPhysical) {
    Student s[4] = {
        { "Melnyk",     1, TRUDOVE_NAVCHANNYA, 3, 3, {3} }, // avg 3.00
        { "Bondarenko", 1, MATEMTAEKONOM,      4, 4, {4} }, // avg 4.00, math 4
        { "Kovalenko",  3, FIZYKA_INFORMATYKA, 3, 5, {4} }, // avg 4.00, math 5
        { "Petrenko",   2, KOMP_NAUKY,         5, 5, {4} }  // avg 4.67, math 5
    };
    Sort(s, 4);

    // Пошук першого, середнього (з округленням 4.67) та останнього елементів
    EXPECT_EQ(BinSearch(s, 4, 3.00, 3, "Melnyk"), 0);
    EXPECT_EQ(BinSearch(s, 4, 4.00, 5, "Kovalenko"), 2);
    EXPECT_EQ(BinSearch(s, 4, 4.67, 5, "Petrenko"), 3);

    // Неіснуючий студент (невідповідність по одному з ключів)
    EXPECT_EQ(BinSearch(s, 4, 4.00, 4, "Unknown"), -1);
    EXPECT_EQ(BinSearch(s, 4, 4.00, 3, "Bondarenko"), -1);
    EXPECT_EQ(BinSearch(s, 4, 2.00, 2, "Melnyk"), -1);
}

// 9. Тест бінарного пошуку за індексним масивом (BinSearchIndex)
TEST(StudentLab10_2B_Test, BinSearchIndexed) {
    Student s[4] = {
        { "Petrenko",   2, KOMP_NAUKY,         5, 5, {4} }, // індекс 0 -> позиція 3 в I (avg 4.67)
        { "Bondarenko", 1, MATEMTAEKONOM,      4, 4, {4} }, // індекс 1 -> позиція 1 в I (avg 4.00)
        { "Melnyk",     1, TRUDOVE_NAVCHANNYA, 3, 3, {3} }, // індекс 2 -> позиція 0 в I (avg 3.00)
        { "Kovalenko",  3, FIZYKA_INFORMATYKA, 3, 5, {4} }  // індекс 3 -> позиція 2 в I (avg 4.00, math 5)
    };

    int* I = IndexSort(s, 4);

    // Перевіряємо позиції в масиві I та відповідність індексам у вихідному масиві s
    int posMelnyk = BinSearchIndex(s, I, 4, 3.00, 3, "Melnyk");
    EXPECT_EQ(posMelnyk, 0);
    EXPECT_EQ(I[posMelnyk], 2);

    int posKovalenko = BinSearchIndex(s, I, 4, 4.00, 5, "Kovalenko");
    EXPECT_EQ(posKovalenko, 2);
    EXPECT_EQ(I[posKovalenko], 3);

    int posPetrenko = BinSearchIndex(s, I, 4, 4.67, 5, "Petrenko");
    EXPECT_EQ(posPetrenko, 3);
    EXPECT_EQ(I[posPetrenko], 0);

    // Пошук відсутнього елемента
    EXPECT_EQ(BinSearchIndex(s, I, 4, 5.00, 5, "Ivanenko"), -1);

    delete[] I;
}