#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void Input(double* a, const int size, int i)
{
cout << "a[" << i << "] = ";
cin >> a[i];
if (i<size-1)
Input(a, size, i+1);
else
cout << endl;
}


void Print(double* p, const int size, int i)
          {  
            cout << setw(8) << p[i];
            if (i<size-1)
            Print(p, size, i+1);
            else
            cout << endl;
            }


int CountGreaterC ( double* a, const int size, double C, int i)
{
    if ( i < size)
    {
        if (a[i]> C)
               
    return 1 + CountGreaterC( a, size,C, i + 1);
else
    return CountGreaterC( a, size,C, i + 1);
    }
    else
        return 0;
 
}


int MaxAbs (double* a, const int size, int i, int iMax)
{
if (fabs(a[i])>fabs(a[iMax]))
iMax=i;
if (i<size-1)
return MaxAbs(a, size, i+1, iMax);
else
return iMax;
}


double MultAfterMax(double* a, const int size, int i)
{
    if (i < size)
        return a[i] * MultAfterMax(a, size, i + 1);
    else
        return 1;
}


void Replace(double* a, const int size, int i, int j)
{
    if (i < size)
    {
        if (j > 0 && a[j] < 0 && a[j - 1] >= 0)
        {
            double tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
            Replace(a, size, i, j - 1);
        }
        else
            Replace(a, size, i + 1, i + 1);
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
Input (a, n, 0);
Print (a, n, 0);

cout << "Кількість елементів, більших за C = " << CountGreaterC(a, n, C, 0) << endl;

int iMax = MaxAbs(a, n, 1, 0);
if (iMax == n - 1)
    cout << "Після максимального за модулем елементів немає, добуток = 1" << endl;
else
    cout << "Добуток = " << MultAfterMax(a, n, iMax + 1) << endl;

Replace(a, n, 0, 0);
Print(a, n, 0);

delete [] a;
return 0;
}