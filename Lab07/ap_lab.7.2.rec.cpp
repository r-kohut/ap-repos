#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void SearchMinColRow(int** a, const int rowNo, const int colCount, int colNo, int& minCol);
void SearchMaxColRow(int** a, const int rowNo, const int colCount, int colNo, int& maxCol);
void SwapMinMaxRow(int** a, const int rowNo, const int colCount);
void SwapMinMaxEvenRows(int** a, const int rowCount, const int colCount, int rowNo);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -50;      
    int High = 50;   

    int rowCount;       // k – кількість рядків матриці
    int colCount;       // n – кількість стовпців матриці
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;
    cout << endl;

    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
    cout << "Початкова матриця:" << endl;
    PrintRows(a, rowCount, colCount, 0);

    // 1 – перший парний рядок за нумерацією з 1 (тобто рядок з індексом 1),
    // далі кожен другий. Для нумерації з 0 передати 0.
    SwapMinMaxEvenRows(a, rowCount, colCount, 1);
    cout << "Матриця після обміну max min y парних рядках:" << endl;
    PrintRows(a, rowCount, colCount, 0);

    for (int i = 0; i < rowCount; i++)
        delete [] a[i];
    delete [] a;

    return 0;
}

// Заповнює випадковими числами рядок rowNo, починаючи зі стовпця colNo
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

// Заповнює випадковими числами всі рядки, починаючи з рядка rowNo
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

// Виводить рядок rowNo, починаючи зі стовпця colNo
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

// Виводить всі рядки, починаючи з рядка rowNo
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

// Шукає НОМЕР СТОВПЦЯ мінімального елемента рядка rowNo.
// minCol – вихідний параметр; перед першим викликом = 0, colNo = 0
void SearchMinColRow(int** a, const int rowNo, const int colCount, int colNo, int& minCol)
{
    if (a[rowNo][colNo] < a[rowNo][minCol])
        minCol = colNo;
    if (colNo < colCount - 1)
        SearchMinColRow(a, rowNo, colCount, colNo + 1, minCol);
}

// Шукає НОМЕР СТОВПЦЯ максимального елемента рядка rowNo.
// maxCol – вихідний параметр; перед першим викликом = 0, colNo = 0
void SearchMaxColRow(int** a, const int rowNo, const int colCount, int colNo, int& maxCol)
{
    if (a[rowNo][colNo] > a[rowNo][maxCol])
        maxCol = colNo;
    if (colNo < colCount - 1)
        SearchMaxColRow(a, rowNo, colCount, colNo + 1, maxCol);
}

// Міняє місцями максимальний і мінімальний елементи рядка rowNo
void SwapMinMaxRow(int** a, const int rowNo, const int colCount)
{
    int minCol = 0;     // номер стовпця мінімального елемента
    int maxCol = 0;     // номер стовпця максимального елемента
    SearchMinColRow(a, rowNo, colCount, 0, minCol);
    SearchMaxColRow(a, rowNo, colCount, 0, maxCol);

    int tmp = a[rowNo][minCol];
    a[rowNo][minCol] = a[rowNo][maxCol];
    a[rowNo][maxCol] = tmp;
}

// Виконує обмін у рядку rowNo, потім переходить через один рядок (rowNo+2)
void SwapMinMaxEvenRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo >= rowCount)      // парних рядків немає 
        return;

    SwapMinMaxRow(a, rowNo, colCount);
    if (rowNo + 2 < rowCount)
        SwapMinMaxEvenRows(a, rowCount, colCount, rowNo + 2);
}