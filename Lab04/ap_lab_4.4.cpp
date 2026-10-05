#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() 
{
    
double R1;
double R2;    
double x; 
double y; 
double xp;
double xk;
double dx;
 
cout << "R1 = " ; cin  >> R1;
cout << "R2 = " ; cin  >> R2;
cout << "xp = "; cin >> xp;
cout << "xk = "; cin >> xk;
cout << "dx = "; cin >> dx;

cout << fixed << setprecision(2);
cout << "-------------------------------" << endl;
cout<< " Таблиця значень функції"<< endl;
cout <<" Параметри: " << "R1= " <<R1 << ", R2= " << R2 << endl;
cout<<" xp = " << xp << ", xk = " << xk << ", dx = " << dx <<  endl;
cout << "-------------------------------" << endl;
cout << "|" << setw(13) << "x" << " |" << setw(13) << "y" << " |" << endl;
cout << "-------------------------------" << endl;
x = xp;
while (x <= xk)
{if (x <= -6)
        y = R2 / 2.0;
    else
        if (-6 < x && x <= -2 * R2)
            y = (R2 *(-2.0 *  R2 - x))/(2.0 * (6.0-2.0 *R2));
        else
            if (-2 * R2 < x && x <= 0)
                y = sqrt(R2 * R2 - (x + R2) * (x + R2));
            else
                if (0 < x && x <= 2 * R1)
                    y = -sqrt(R1 * R1 - (x - R1) * (x - R1));
                else
                    y = -R1 * (x - 2 * R1);
                cout << fixed; setprecision(2);
                cout << "| " << setw(12) << x << " | " << setw(12) << y << " |" << endl;
                x += dx;
}

cout << "-------------------------------" << endl;

 return 0;
}