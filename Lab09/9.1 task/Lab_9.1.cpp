//////////////////////////////////////////////////////////////////////////////
// Lab_9.1.cpp
// головний файл проекту: функція main
#include <iostream>
#include <iomanip>
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    if (dx <= 0 || e <= 0 || x_p > x_k)
    {
        cout << "Error: need dx > 0, e > 0 and x_p <= x_k" << endl;
        return 1;
    }

    // заголовок і шапка таблиці
    cout << string(54, '-') << endl;
    cout << "|" << setw(10) << "x"
         << "|" << setw(14) << "sin(x)/x"
         << "|" << setw(14) << "series sum"
         << "|" << setw(10) << "terms" << "|" << endl;
    cout << string(54, '-') << endl;

    for (int k = 0; x_p + k * dx <= x_k + 1e-9; k++)
    {
        x = x_p + k * dx;               // аргумент без накопичення похибки
        sum();                          // обчислення суми ряду

        double f = (fabs(x) < 1e-12) ? 1.0 : sin(x) / x;   // у точці x = 0 границя дорівнює 1

        cout << fixed << setprecision(6)
             << "|" << setw(10) << x
             << "|" << setw(14) << f
             << "|" << setw(14) << s
             << "|" << setw(10) << n << "|" << endl;
    }
    cout << string(54, '-') << endl;

    return 0;
}