#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
    {
    a[i] = Low + rand() % (High-Low+1);
    if (i<size-1)
    Create(a, size, Low, High, i+1);
    }

        void Print(int* a, const int size, int i)
          {  
            cout << setw(4) << a[i];
            if (i<size-1)
            Print(a, size, i+1);
            else
            cout << endl;
            }

    int Max(int* a, const int size, int i, int max)
    {
    if (a[i]>max)
    max=a[i];
    if (i<size-1)
    return Max(a, size, i+1, max);
    else
    return max;
    }

int Min(int* a, const int size, int i, int min)
    {
    if (a[i]< min)
    min=a[i];
    if (i<size-1)
    return Min(a, size, i+1, min);
    else
    return min;
    }

int Sum(int* a, const int size)
{
    return Max(a, size, 1, a[0]) + Min(a, size, 1, a[0]);
}


int main()
 {
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n=20;
    int a[n];
    int Low = -20;
    int High = 34;
    Create(a, n, Low, High, 0);
    Print(a, n, 0);
    cout << "Максимальне значення = " << Max(a, n, 1, a[0]) << endl;
    cout << "Мінімальне значення = " << Min(a, n, 1, a[0]) << endl;
    cout << "Сума цих значень = " << Sum(a, n) << endl;
    return 0;
    }