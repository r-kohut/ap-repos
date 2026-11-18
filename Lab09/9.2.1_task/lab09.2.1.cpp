#include <iostream>
using namespace std;

#ifndef Z
#define Z 1                 // значення z; можна змінити тут
#endif

#define SQR(a)    ((a) * (a))
#define ABS(a)    (((a) < 0) ? -(a) : (a))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define PRINT(w)  cout << #w << " = " << (w) << endl

int main()
{
    double x, y, w;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    cout << "control output" << endl;
    PRINT(x);
    PRINT(y);
    PRINT(Z);

#if Z == 1                  // гілка z = 1
    cout << "branch: z = 1" << endl;
    w = MIN(SQR(x - y), ABS(y - x));
#else                       // гілка z != 1
    cout << "branch: z != 1" << endl;
    double z = Z;
    w = MAX(x + SQR(y), z + SQR(x));
#endif

    cout << "result:" << endl;
    PRINT(w);

    return 0;
}