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

              void PrintNeg(int* p, const int size, int i)
              
                  {
                    
                      if (p[i] < 0 && p[i] % 2 == 0)
                          cout << setw(4) << p[i];

                      if (i < size - 1)
                          PrintNeg(p, size, i + 1);
                      else
                          cout << endl;
                  }

                     int Sum(int* p, const int size, int i, int S)
                      {
                          if (p[i] < 0 && p[i] % 2 == 0)
                              S += p[i];

                          if (i < size - 1)
                              return Sum(p, size, i + 1, S);
                          else
                              return S;
                      }

                      int Quant(int* p, const int size, int i, int k)
                            {
                                if (p[i] < 0 && p[i] % 2 == 0)
                                    k++;

                                if (i < size - 1)
                                    return Quant(p, size, i + 1, k);
                                else
                                    return k;
                            }

                                void Zero(int* p, const int size, int i)
                                    {
                                    if (p[i] < 0 && p[i] % 2 == 0)
                                    p[i] = 0;
                                    if (i<size-1)
                                      Zero(p, size, i+1);
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
    cout<< "Вивід парних відємних чисел" << endl;
    PrintNeg(p, n, 0);
    cout << " Сума =  " << Sum(p, n, 0, 0) << endl;
    cout << " Кількість = " << Quant(p, n, 0, 0) << endl;
    cout<< "Вивід замінених парних відємних чисел на 0" << endl;
    Zero (p, n, 0);
    Print(p, n, 0);
    return 0;
    }