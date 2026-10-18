#include <iostream>
#include <cmath>
using namespace std;
//iter
double S0(const int N)
{
     double s=1;
    for(double k = 1; k <= N; k++)
        s *=  (k*k)/(N*N) * cos(((N*N))/(k*k));
        return s;

}
//rec up ++
double S1( const int N, double k = 1)
{
    if (k > N)
    return 1;
        else 
            return (k*k)/(N*N) * cos(((N*N))/(k*k)) * S1( N, k+1);
}
//rec up --
double S2( const int N, double k)
{
    if (k < 1)
        return 1;
            else    
                return (k*k)/(N*N) * cos(((N*N))/(k*k)) * S2( N, k - 1);
}

//rec down ++ 
double S3 ( const int N, double k, double t)
{
    t = t * (k*k)/(N*N) * cos(((N*N))/(k*k));
    if (k >= N)
    return t;
        else 
            return S3 (N, k + 1, t);

}

// rec down --
double S4 (const int N, double k, double t)

{
t = t * (k*k)/(N*N) * cos(((N*N))/(k*k));
if ( k <= 1)
    return t;
    else 
        return S4(N, k - 1,t);
}
int main()
{
    int N;
    cout<<"N = "; cin >> N;


    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(N, 1) << endl;
    cout << "(rec up --) S2 = " << S2(N, N) << endl;
    cout << "(rec down ++)  S3 = " << S3(N, 1 ,1.0) << endl;
    cout << "(rec down --) S4 = " << S4(N, N , 1.0) << endl;

return 0;

}
