#include <iostream>
#include <iomanip>
#include <time.h> 
#include <cmath>
using namespace std;
int main()
{
    double x, y, R ;
    cout << "R = "; cin >> R;
    
    srand((unsigned) time(NULL));
    cout << "|" << setw(5) << "x" << "   |" << setw(6) << "y" << "     |" << endl;
     

     for( int i = 0; i <10; i++)
     {
        x = 2*R * ((double)rand() / (RAND_MAX)) - R;
        y = 2*R * ((double)rand() / (RAND_MAX)) - R;


            if (((pow(x + R, 2) + pow(y - R, 2) >= R * R) && (-R <= x) && (x <= 0) && (0 <= y) && (y <= R) ||
        (x * x + y * y <= R * R) && (x >= 0) && (y <= 0)))
            
        cout << setw(8) << setprecision(4) << x << " "
                << setw(8) << setprecision(4) << y << " " << "yes" << endl;
    
    else 
         
    cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << " " << "no" << endl;
     }
return 0;
}
