#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{


  double x; 
  double y; 
  double B;  
  double A; 
  double xp;
  double xk;
  double dx;


cout << "xp = "; cin >> xp;
cout << "xk = "; cin >> xk;
cout << "dx = "; cin >> dx;
  
  
cout << fixed;
cout << "---------------------------" << endl;
cout << "|" << setw(5) << "x" << " |"
<< setw(7) << "y" << " |" << endl;
cout << "---------------------------" << endl;
x = xp;
while (x <= xk)
{
 
 
 
  A = pow(x , 3) + 2;


  if (x < 4)
    B = 5 * pow (x , 8) + pow(x , 6) - x*x +3;
  else
    if ( 4 <= x && x <7)
      B = atan (fabs((x + 3)/2.0)) + 7*x;
    else
      B = log10( 2*x + exp( 5*x + 5));

  y = A + B;
  

cout << "|" << setw(7) << setprecision(2) << x
<< " |" << setw(10) << setprecision(3) << y
<< " |" << endl;
x += dx;
}
cout << "---------------------------" << endl;
return 0;
}