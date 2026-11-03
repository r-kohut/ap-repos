#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n,const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
int MinInRow(int** a, const int rowNo, const int n);
int MaxInRow(int** a, const int rowNo, const int n);
void Change(int** a, const int i, const int minCol, const int maxCol);
void ChangeEvenRows( int ** a, const int n, const int k);


int main()
{
    srand((unsigned)time(NULL));
    int Low = -34;
    int High = 34;
    int k;
    cout << "k = "; cin >> k;
    int n;
    cout << "n = "; cin >> n;

    int **a = new int*[k];
    for (int i=0; i<k; i++)
    a[i] = new int[n];
    Create (a, n , k, Low, High);
    Print (a, n, k);
    ChangeEvenRows(a, n, k);
    Print (a, n, k);


    for ( int i = 0; i < k; i ++)
    delete [] a [i];
    delete [] a;
     return 0;
}


void Create(int ** a, const int n, const int k, const int Low, const int High)
{
    for (int i = 0; i < k; i ++)
        for (int j = 0; j < n; j++)
            a[i][ j] = Low + rand() % (High - Low + 1);
}

void Print (int ** a, const int n, const int k)
{
    cout << endl;
    for ( int i = 0; i < k ; i ++ )
    {
        for ( int j = 0; j < n ; j ++)
        cout << setw (4) << a[i][j];
    cout << endl;
  }
  cout << endl;
}


 int MinInRow(int** a, const int rowNo, const int n)
{
int minCol = 0;
for ( int j = 1; j < n ; j++)

    if (a[rowNo][j] < a[rowNo][minCol])
        minCol = j;
return minCol;
}

int MaxInRow(int** a, const int rowNo, const int n)
{
int maxCol = 0;
for ( int j = 1; j < n ; j++)

    if (a[rowNo][j] > a[rowNo][maxCol])
        maxCol = j;
return maxCol;
}

void Change(int** a, const int i, const int minCol, const int maxCol)
{
int tmp;
tmp = a[i][maxCol];
a[i][maxCol] = a[i][minCol];
a[i][minCol] = tmp;
}

void ChangeEvenRows( int ** a, const int n, const int k)
{
    for (int i = 1; i < k; i += 2)
    {
        int minCol = MinInRow(a, i, n);
        cout << "Min в рядку " << i << " = " << a[i][minCol] << endl;
        int maxCol = MaxInRow(a, i, n);
        cout << "Max в рядку " << i << " = " << a[i][maxCol] << endl;
        cout << endl;
        Change (a, i, minCol, maxCol);
    }
}