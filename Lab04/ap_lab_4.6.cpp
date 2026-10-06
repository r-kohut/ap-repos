#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double S;
    int n, k;
    
   
    S = 0;
    n = 1;
    while (n <=18) //перший спосіб
    {   
         k = n;
        while (k <= 20)
        {
         
        S += sqrt(fabs(1. - 1. * k / n)) / (2. * n * n + k * k);
            k++;
        }
        n++;
    }
cout << "1) S = " << S << endl;

S = 0;
n = 1;

do { //другий спосіб
    k = n;
    do {
        S += sqrt(fabs(1. - 1. * k / n)) / (2. * n * n + k * k);
        k++;
    } while (k <= 20);

    n++;

} while (n <= 18);

cout << "2) S = " << S << endl;
   
S = 0;
 for ( n =1; n <= 18; n++) //третій спосіб
 {
    for ( k = n; k <= 20; k++)
    {
        S += sqrt(fabs(1. - 1. * k / n)) / (2. * n * n + k * k);
    }
 }
 cout << "3) S = " << S << endl;

S = 0;

for (n = 18; n >= 1; n--)
{
    for ( k =20; k>=n; k--)
    {
        S += sqrt(fabs(1. - 1. * k / n)) / (2. * n * n + k * k);
    }
}
cout << "4) S = " << S << endl;


return 0;

}