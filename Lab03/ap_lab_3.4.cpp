// Lab_03_4.cpp
// Когут Роман
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 15
#include <iostream>
#include <cmath>
using namespace std;

int main()
{   
    
    double R;
    double x;
    double y;
    cout << "R= "; cin >> R;
    cout << "y= "; cin >> y;
    cout << "x= "; cin >> x;

    if (((pow(x + R, 2) + pow(y - R, 2) >= R * R) && (-R <= x) && (x <= 0) && (0 <= y) && (y <= R) ||
        (x * x + y * y <= R * R) && (x >= 0) && (y <= 0)))
            cout << "Yes" << endl;
    
    else 
         cout << "No" << endl;

    
cin.get();

return 0;

    
}
    

   





















