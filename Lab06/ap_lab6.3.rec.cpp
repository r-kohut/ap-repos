#include <iostream>
#include<iomanip>
#include <time.h>
using namespace std;
    void Create(int* p, const int size, const int Low, const int High, int i)
    {
    p[i] = Low + rand() % (High-Low+1);
    if (i<size-1)
    Create(p, size, Low, High, i+1);
    }



void Print(int* p, const int size, int i)
{  
    cout << setw(4) << p[i];
        if (i<size-1)
        Print(p, size, i+1);
            else
            cout << endl;
}
   
   
   
 int Quant(int* p, const int size, int i, int k = 0)
{
    if (p[i] % 2 == 0)
        k++;

    if (i < size - 1)
      return Quant(p, size, i + 1, k);
          else
             return k;
            
}

template <typename T>
int Quant(T* p, const int size, int i, int k = 0)
{
    if (p[i] % 2 == 0)
        k++;

    if (i < size - 1)
      return Quant(p, size, i + 1, k);
          else
             return k;
            
}

template <typename T>
void Print(T* p, const int size, int i)
{  
    cout << setw(4) << p[i];
        if (i<size-1)
        Print(p, size, i+1);
            else
            cout << endl;
}


int main()
{
srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
const int n=20;
int p[n];
int Low = -20;
int High = 34;
Create(p, n, Low, High, 0);
Print(p, n, 0);
cout << "Кількість парних елементів масиву (звичайна функція) = " << Quant( p, n, 0)<< endl;
cout << "Кількість парних елементів (шаблон int) = " << Quant<int>(p, n, 0) << endl;
long long b[5] = { 2, 3, 4, 7, 10 };
Print (b, 5, 0);
cout << "Кількість парних елементів (шаблон long long) = " << Quant<long long>(b, 5, 0) << endl;
return 0;
}