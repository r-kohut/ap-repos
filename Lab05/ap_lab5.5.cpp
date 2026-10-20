#include <iostream>
#include <cmath>
using namespace std;

int sumn( int n)
{
    if (n < 10) // якщо цифра одна то і є сумою
    return n;
        else 
            return (n % 10) + sumn(n / 10); // остання цифра плюс сума решти
}

int quant( int n )
{
    if ( n < 10 ) // одна цифра має 1 кількість
    return 1;
    else 
        return 1 + quant( n / 10); // 1 плюс кідькість цифр у решті
}

int mmax ( int n )
{
    if ( n < 10 )
    return n; 
        else 
            {
            int last = n % 10; // визначення останньої цифри
            int rest_max = mmax (n / 10); //максимум серед решти цифр 
            
                if (last > rest_max)
                    return last;
                        else 
                            return rest_max;
                                            }
}
int mmin ( int n )
{
    if ( n < 10 )
    return n; 
        else 
            {
            int last = n % 10; // визначення останньої цифри
            int rest_min = mmin (n / 10); //мінімум серед решти цифр 
            
                if (last < rest_min)
                    return last;
                        else 
                            return rest_min;
                                            }
}

int main ()
{
int n;
 cout << " Введіть число = "; 
 cin >> n;
n = abs(n);

cout << " Сума цифр =  " << sumn(n) << endl;
cout << " Кількість цифр = " << quant (n) << endl;
cout << " Максимальне значення = " << mmax (n) << endl;
cout << " Мінімальне значення = " << mmin (n) << endl;
cout << " Глибина рекурсії = "<< quant (n)<< endl;

return 0;
}