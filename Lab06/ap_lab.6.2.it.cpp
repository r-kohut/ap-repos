#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>
using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
for (int i=0; i<size; i++)
a[i] = Low + rand() % (High-Low+1);
}

void Print(int* a, const int size)
    {
    for (int i=0; i<size; i++)
    cout << setw(4) << a[i];
    cout << endl;
    }


int Max (int* a, const int size)
{
    int max = a[0];
    for ( int i = 1; i < size; i++)
        if (a [i] > max)
        max = a[i];
        return max;
}
    

int Min (int* a, const int size)
{
    int min = a[0];
    for ( int i = 1; i < size; i++)
        if (a [i] < min)
        min = a[i];
        return min;
}


int Sum(int* a, const int size)
{
    return Max(a, size) + Min(a, size);
}


int main()
{
srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
const int n=20;
int a[n];
int Low = -20;
int High = 34;
Create(a, n, Low, High);
Print(a, n);
cout << "Максимальне значення = "<< Max(a,n )<< endl;
cout << "Мінімальне значення = "<< Min(a,n )<< endl;
cout << "Сума цих значень "<< Sum(a ,n)<< endl;
return 0;
}