#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double z(const double x);

int main ()
{
    double pp, pk, i;
    int n;

    cout << "pp= "; cin >> pp;
    cout << "pk= "; cin >> pk;
    cout << "n= "; cin >> n;
    
    double dp = (pk - pp)/n;
    double p = pp;
    cout << "--------------------"<<endl;
    cout << "|" << setw(5) << "p" << " |" << setw(10) << " Результат" << " |"<< endl;
    cout << "--------------------" << endl;
    while (p <= pk)
    {
        i = z(p*p) + 2*z(2*p + p*p)+1;
       
        cout << "|" << setw(5) << p << " |" << setw(10) << i << " |" << endl;
         p+=dp;
    } 
    cout<< "--------------------" << endl;
          
    return 0;
}
double z(const double x)
{
if (abs(x) >= 1)
  
return (cos(2*x )+ 1) / (cos(x)+(sin(x)*sin(x)));

    else 
    {
        double S = 0;
        int k = 0;  
        double a = 2*x;
        S = a;
        do
        {
            k++;
            double R = (4 * x * x) / (2.0 * k * (2.0 * k + 1.0));
            a *= R;
            S += a;
        } while (k<6);
        return S;
    }
}

