#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



int main()
 {

double a; 
double b; 
double c; 
double x; 
double F; 
double xp;
double xk;
double dx;
 cout << "a = "; cin >> a;
 cout << "b = "; cin >> b;
 cout << "c = "; cin >> c;
 cout << "xp = "; cin >> xp;
 cout << "xk = "; cin >> xk;
 cout << "dx = "; cin >> dx;
cout << fixed;
cout << "---------------------------" << endl;
cout << "|" << setw(5) << "x" << "   |"
<< setw(7) << "F" << "    |" << endl;
cout << "---------------------------" << endl;
x = xp;
while (x <= xk)
{






 if ( x< 0 && b != 0)
     F = -a * x * x + b;
    
     if ( x > 0 && b == 0 )
        F = x / (x - c) + 5.5;
           
     else
        F = x / (-c);

        
cout << "|" << setw(7) << setprecision(2) << x
<< " |" << setw(10) << setprecision(3) << F
<< " |" << endl;
x += dx;
}
cout << "---------------------------" << endl;
  
return 0;
 
}



