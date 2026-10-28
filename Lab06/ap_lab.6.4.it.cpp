#include <iostream>
#include <cmath>
#include <time.h>
#include <iomanip>
using namespace std;


void Input ( double* a, const int size)
{
    for ( int i = 0; i < size; i++)
    {
        cout << "a [" << i << "] = ";
        cin >> a[i];
    }
}


void Print ( double* a, const int size)
{
    for (int i = 0; i < size; i++)
    cout << setw(8)<< a[i];
    cout << endl;
}


int CountGreaterC ( double* a, const int size, double C)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i]> C)
        k++;
    }
    return k;
}



int MaxAbs(double* a, const int size)
{
int iMax = 0;
for (int i=1; i<size ; i++)
if (abs(a[i])> abs(a[iMax]))
    iMax=i;
return iMax;
}


double MultAfterMax(double* a, const int size, int iMax)
{
double P = 1;
for ( int i = iMax + 1; i < size; i ++)
    P *= a[i];
return P;
}


void Replace(double* a, const int size ) //метод вставки
{
    int pos = 0; //куди вставити наступний відʼємний елемент
    for (int i = 0; i < size; i ++)
    if (a[i] < 0)
    {
        double tmp = a[i]; //вибрали елемент для вставки 
        for ( int k = i - 1; k >= pos; k-- )
            a[k + 1] = a[k];
        a[pos] = tmp;
        pos++;
    }
}


int main()
{
int n;
double C;
cout << "n = ";
cin >> n;
cout << "C = ";
cin >> C;

double* a = new double [n];
Input (a, n);
Print (a, n);

cout << "Кількість елементів більших за С = " << CountGreaterC(a, n, C)<< endl;
int iMax = MaxAbs(a, n);
if (iMax == n - 1)
    cout << "Після максимального за модулем елементів немає, добуток = 1" << endl;
else
    cout << "Добуток = " << MultAfterMax(a, n, iMax) << endl;

Replace (a, n);
Print(a, n);

delete [] a;
return 0;
}