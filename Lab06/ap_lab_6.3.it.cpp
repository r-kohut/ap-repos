#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void Create (int*p, const int size, int High, int Low)
{
    for ( int i=0; i<size; i ++ )
    p[i]= Low + rand()%(High - Low +1);


}

void Print (int *p, const int size )
{
for ( int i = 0; i<size; i++)
    cout<< setw (4)<< p[i];
    cout<<endl;
}

int Quant( int *p, const int size)
{
    int k = 0;
    for( int i = 0 ; i < size; i++)
        if (p[i]%2 == 0)
            k++;
    return k;
}

template <typename T> //Шаблон функції Quant
int Quant( T *p, const int size)
{
    int k = 0;
    for( int i = 0 ; i < size; i++)
        if (p[i]%2 == 0)
            k++;
    return k;
}


 int main()
{

srand((unsigned)time(NULL));
const int n = 20;
int p[n];
int Low = -20;
int High = 34;
Create(p, n, High, Low);
Print (p, n);
cout << "Кількість парних елементів масиву (звичайна функція) = " << Quant( p, n)<< endl;
cout << "Кількість парних елементів (шаблон int) = " << Quant<int>(p, n) << endl;
long long b[5] = { 2, 3, 4, 7, 10 };
cout << "Кількість парних елементів (шаблон long long) = " << Quant<long long>(b, 5) << endl;
return 0;
}




