#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* p, const int size, const int Low, const int High)
{
for (int i=0; i<size; i++)
p[i] = Low + rand() % (High-Low+1);
}

    void Print(int* p, const int size)
    {
    for (int i=0; i<size; i++)
    cout << setw(4) << p[i];
    cout << endl;
    }

            void PrintNeg(int* p, const int size)
                {
                cout<< "Вивід парних відємних чисел" << endl;
                for (int i=0; i<size; i++)
                if ( p [i] < 0 && p [i] % 2 == 0)
                cout << setw(4)<< p[i];
                cout << endl;
                }

            int Sum(int* p, const int size)
                {
                    int S = 0;
                    for (int i = 0; i < size; i++)
                        if (p[i] < 0 && p[i] % 2 == 0)
                            S += p[i];
                    return S;
                    
                }

                        int Quant(int* p, const int size)
                    {
                        int k = 0;
                        for (int i = 0; i < size; i++)
                            if (p[i] < 0 && p[i] % 2 == 0)
                                k ++;
                        return k;
                        
                    }
                            void Zero(int* p, const int size)
                            {
                                cout<< "Вивід замінених парних відємних чисел на 0" << endl;
                                for (int i = 0; i < size; i++)
                                    if (p[i] < 0 && p[i] % 2 == 0)
                                        p[i] = 0;
                            }

int main()
{
srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
const int n=20;
int p[n];
int Low = -20;
int High = 34;
Create(p, n, Low, High);
Print(p, n);
PrintNeg(p, n);
int S = Sum (p, n);
cout <<" Сума = " << S << endl;
cout << " Кількість елементів у списку = "<< Quant (p, n) << endl;
Zero (p, n);
Print(p, n);
return 0;
}