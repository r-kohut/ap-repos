#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
    int N , k;   
    double S;
    cout << "N = " ; cin >> N;
    S = 0;
    k = 1;
    while (k <= N)  // перший спосіб оформлення циклу
    {
        S += (k*k)/(N*N) * cos((N*N)/(k*k));
        k++;

    }
cout << "1) S = " << S << endl;


S = 0;              // другий спосіб оформлення циклу
k = 1;
do {
    S += (k*k)/(N*N) * cos((N*N)/(k*k));
        k++;

} while (k <= N);

cout << "2) S = " << S << endl;


S = 0;               //третій спосіб оформлення циклу

for ( k = 1 ;k <= N; k++ ) 
{
    S += (k*k)/(N*N) * cos((N*N)/(k*k));
}
cout << "3) S = " << S << endl;

S = 0; 

for ( k = N; k>=1; k-- ) 
{
    S += (k*k)/(N*N) * cos((N*N)/(k*k));
}
cout << "4) S = " << S << endl;



    return 0;
}




