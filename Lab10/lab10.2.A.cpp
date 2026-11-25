// Лабораторна робота № 10.2, рівень А, варіант 15
// Впорядкування (фізичне та індексне) та бінарний пошук в масиві структур
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

enum Spec { KOMP_NAUKY, INFORMATYKA, MATEMTAEKONOM, FIZYKA_INFORMATYKA, TRUDOVE_NAVCHANNYA };

struct Student {
    string prizv;
    int kurs;
    Spec spec;
    int fizyka;
    int matematyka;
    int informatyka;
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
void PrintIndexSorted(const Student* s, const int* I, const int N);
void PrintHeader();
void PrintRow(const Student& st, const int number);
void PrintLine();
string SpecToString(const Spec spec);
string Pad(const string& str, const int width);
double Average(const Student& s);
int Compare(const Student& s, const double avg, const int math, const string& prizv);
void Sort(Student* s, const int N);
int* IndexSort(const Student* s, const int N);
int BinSearch(const Student* s, const int N,
              const double avg, const int math, const string& prizv);
int BinSearchIndex(const Student* s, const int* I, const int N,
                   const double avg, const int math, const string& prizv);
void ReadKeys(string& prizv, double& avg, int& math);

int main()
{
    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Student* s = new Student[N];
    int* I = NULL;              // індексний масив (NULL - ще не побудований)
    bool filled = false;        // чи введені дані
    bool sorted = false;        // чи масив впорядкований фізично

    string prizv;
    double avg;
    int math, found;
    int menuItem;
    do
    {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - індексне впорядкування та вивід за індексним масивом" << endl;
        cout << " [5] - бінарний пошук студента у фізично впорядкованому масиві" << endl;
        cout << " [6] - бінарний пошук студента за індексним масивом" << endl << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl;

        if (cin.fail())             // введено не число - завершуємо роботу
            break;

        if (menuItem >= 2 && menuItem <= 6 && !filled)
        {
            cout << "Спочатку введіть дані (пункт 1)!" << endl;
            continue;
        }

        switch (menuItem)
        {
        case 1:
            Create(s, N);
            filled = true;
            sorted = false;
            delete[] I;
            I = NULL;
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            Sort(s, N);
            sorted = true;
            delete[] I;             // порядок елементів змінився
            I = NULL;
            cout << "Масив фізично впорядковано." << endl;
            Print(s, N);
            break;
        case 4:
            delete[] I;
            I = IndexSort(s, N);
            PrintIndexSorted(s, I, N);
            break;
        case 5:
            if (!sorted)
            {
                cout << "Спочатку впорядкуйте масив фізично (пункт 3)!" << endl;
                break;
            }
            ReadKeys(prizv, avg, math);
            found = BinSearch(s, N, avg, math, prizv);
            if (found != -1)
                cout << "Знайдено студента в позиції " << found + 1 << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        case 6:
            if (I == NULL)
            {
                cout << "Спочатку побудуйте індексний масив (пункт 4)!" << endl;
                break;
            }
            ReadKeys(prizv, avg, math);
            found = BinSearchIndex(s, I, N, avg, math, prizv);
            if (found != -1)
                cout << "Знайдено студента в позиції " << found + 1
                     << " індексного порядку (елемент масиву № " << I[found] + 1 << ")" << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        }
    } while (menuItem != 0);

    delete[] I;
    delete[] s;
    return 0;
}

void Create(Student* s, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент №" << i + 1 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - мат. та екон., 3 - фіз. та інф., 4 - труд. навч.): "; cin >> spec;
        s[i].spec = (Spec)spec;
        cout << "  оцінка з фізики: ";      cin >> s[i].fizyka;
        cout << "  оцінка з математики: ";  cin >> s[i].matematyka;
        cout << "  оцінка з інформатики: "; cin >> s[i].informatyka;
        cout << endl;
    }
}

// Вводить ключі пошуку: прізвище, середній бал, оцінка з математики
void ReadKeys(string& prizv, double& avg, int& math)
{
    cout << "Введіть ключі пошуку:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  прізвище: "; getline(cin, prizv);
    cout << "  середній бал (два знаки після крапки, напр. 4.33): "; cin >> avg;
    cout << "  оцінка з математики: "; cin >> math;
    cout << endl;
}

string SpecToString(const Spec spec)
{
    switch (spec)
    {
    case KOMP_NAUKY:         return "Комп'ютерні науки";
    case INFORMATYKA:        return "Інформатика";
    case MATEMTAEKONOM:      return "Математика та економіка";
    case FIZYKA_INFORMATYKA: return "Фізика та інформатика";
    case TRUDOVE_NAVCHANNYA: return "Трудове навчання";
    }
    return "";
}

// Доповнює рядок пробілами до width символів
// (setw рахує байти, а кожна літера кирилиці займає два байти)
string Pad(const string& str, const int width)
{
    int len = 0;
    for (size_t i = 0; i < str.size(); i++)
        if ((str[i] & 0xC0) != 0x80)
            len++;
    return len < width ? str + string(width - len, ' ') : str;
}

void PrintLine()
{
    cout << string(86, '-') << endl;
}

void PrintHeader()
{
    PrintLine();
    cout << "| " << Pad("№", 3)
         << " | " << Pad("Прізвище", 15)
         << " | " << Pad("Курс", 4)
         << " | " << Pad("Спеціальність", 23)
         << " | " << Pad("Фізика", 6)
         << " | " << Pad("Матем.", 6)
         << " | " << Pad("Інформ.", 7) << " |" << endl;
    PrintLine();
}

void PrintRow(const Student& st, const int number)
{
    cout << "| " << setw(3) << right << number
         << " | " << Pad(st.prizv, 15)
         << " | " << setw(4) << right << st.kurs
         << " | " << Pad(SpecToString(st.spec), 23)
         << " | " << setw(6) << right << st.fizyka
         << " | " << setw(6) << st.matematyka
         << " | " << setw(7) << st.informatyka << " |" << endl;
}

void Print(const Student* s, const int N)
{
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(s[i], i + 1);
    PrintLine();
    cout << endl;
}

// Виводить студентів у порядку, заданому індексним масивом I
void PrintIndexSorted(const Student* s, const int* I, const int N)
{
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(s[I[i]], i + 1);
    PrintLine();
    cout << endl;
}

double Average(const Student& s)
{
    return (s.fizyka + s.matematyka + s.informatyka) / 3.0;
}

// Порівнює студента s з ключами (середній бал, оцінка з математики, прізвище):
// -1 - студент "менший", 0 - збігається, 1 - "більший"
int Compare(const Student& s, const double avg, const int math, const string& prizv)
{
    if (fabs(Average(s) - avg) > 0.005)     // середні бали різні
        return Average(s) < avg ? -1 : 1;
    if (s.matematyka != math)
        return s.matematyka < math ? -1 : 1;
    if (s.prizv != prizv)
        return s.prizv < prizv ? -1 : 1;
    return 0;
}

// Фізичне впорядкування методом "бульбашки":
// за середнім балом, далі за оцінкою з математики, далі за прізвищем (за зростанням)
void Sort(Student* s, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (Compare(s[i1], Average(s[i1 + 1]), s[i1 + 1].matematyka, s[i1 + 1].prizv) > 0)
            {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
}

// Індексне впорядкування методом вставки: масив s не змінюється
int* IndexSort(const Student* s, const int N)
{
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    int i, j, value;
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
             j >= 0 && Compare(s[I[j]], Average(s[value]), s[value].matematyka, s[value].prizv) > 0;
             j--)
            I[j + 1] = I[j];
        I[j + 1] = value;
    }
    return I;
}

// Бінарний пошук у фізично впорядкованому масиві; повертає індекс або -1
int BinSearch(const Student* s, const int N,
              const double avg, const int math, const string& prizv)
{
    int L = 0, R = N - 1, m;
    while (L <= R)
    {
        m = (L + R) / 2;
        int c = Compare(s[m], avg, math, prizv);
        if (c == 0)
            return m;
        if (c < 0)
            L = m + 1;
        else
            R = m - 1;
    }
    return -1;
}

// Бінарний пошук за індексним масивом; повертає позицію в масиві I або -1
int BinSearchIndex(const Student* s, const int* I, const int N,
                   const double avg, const int math, const string& prizv)
{
    int L = 0, R = N - 1, m;
    while (L <= R)
    {
        m = (L + R) / 2;
        int c = Compare(s[I[m]], avg, math, prizv);
        if (c == 0)
            return m;
        if (c < 0)
            L = m + 1;
        else
            R = m - 1;
    }
    return -1;
}
