#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

enum Spec {KOMP_NAUKY, INFORMATYKA, MATEMTAEKONOM,FIZYKA_INFORMATYKA, TRUDOVE_NAVCHANNYA };

struct Student {
    string prizv;
    int kurs;
    Spec spec;
    int fizyka;
    int matematyka;
    union {
        int programming;
        int informatyka;
        int pedahohika;


    };
};

void Create(Student* s,  const int N);
void Print (const Student* s,  const int N);
string SpecToString(const Spec spec);
int ThirdGrade(const Student& s);
double Average(const Student& s);
double AverageMax(const Student* s, const int N);
double PercentFizyka4or5( const Student* s, const int N);


int main()
{
    int N;

cout << "Введіть кількість студентів: "; cin >> N;
Student* s = new Student [N];

Create (s, N);
Print (s, N);

cout << fixed << setprecision(2);

cout << "Найвищий середній бал серед студентів: " << AverageMax(s, N) << endl;
cout << "Середня кількість студентів з 4 або 5 з фізики: " << PercentFizyka4or5 (s, N) << endl;

delete [] s;
return 0;
}

void Create (Student* s,  const int N)
{
    int spec;
    for (int i = 0; i < N ; i++)
    {
        cout << "Студент №" << i + 1 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "прізвище :"; getline(cin, s[i].prizv);
        cout << "курс: "; cin >> s[i].kurs;
        cout << "спеціальність (0 - компютерні науки, 1 - Інформатика, 2 - Мат. та екон., 3 - Фіз. та інф., 4 - Труд. навч.): "; cin >> spec;
        
        s[i].spec = (Spec)spec;

        cout << "  оцінка з фізики: ";       cin >> s[i].fizyka;
        cout << "  оцінка з математики: ";   cin >> s[i].matematyka;
        switch (s[i].spec)
        {
            case KOMP_NAUKY:
                cout << " Оцінки з програмування: "; cin >> s [i].programming;
                break;
            case INFORMATYKA:
                cout << "Оцінка з інформатики: "; cin >> s[i].informatyka;
                break;
            default:
                cout << " Оцінка з педагогіки: "; cin >> s[i].pedahohika;
                break;


        }
        cout << endl;
    }
}

string SpecToString (const Spec spec)
{
    switch (spec)
    {case KOMP_NAUKY: return "Комп. науки";
    case INFORMATYKA: return "інформатика";
    case MATEMTAEKONOM: return " Мат. та економіка";
    case FIZYKA_INFORMATYKA: return " Фіз. та інформатика";
    case TRUDOVE_NAVCHANNYA: return "Трудове";
}
 return "";   
}

void Print(const Student* s, const int N)
{
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "| №   | Прізвище        | курс | Спеціальність        | Фізика | Матем. | Інформ. |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
             << " | " << setw(15) << left << s[i].prizv
             << " | " << setw(4) << right << s[i].kurs
             << " | " << setw(20) << left << SpecToString(s[i].spec)
             << " | " << setw(6) << right << s[i].fizyka
             << " | " << setw(6) << s[i].matematyka
             << " | " ;
             switch (s[i].spec)
        {
        case KOMP_NAUKY:
            cout << setw(8) << s[i].programming
                 << " | " << setw(10) << ""
                 << " | " << setw(8) << "" << " |";
            break;
        case INFORMATYKA:
            cout << setw(8) << ""
                 << " | " << setw(10) << s[i].informatyka
                 << " | " << setw(8) << "" << " |";
            break;
        default:
            cout << setw(8) << ""
                 << " | " << setw(10) << ""
                 << " | " << setw(8) << s[i].pedahohika << " |";
            break;
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << endl;
}

int ThirdGrade(const Student& s)
{
    switch (s.spec)
    {
    case KOMP_NAUKY:  return s.programming;
    case INFORMATYKA: return s.informatyka;
    default:          return s.pedahohika;
    }
}

double Average(const Student& s)
{
    return (s.fizyka + s.matematyka + ThirdGrade(s))/ 3.0;
}


double AverageMax( const Student* s, const int N)
{
    double max = Average (s[0]);
    for ( int i = 0; i < N ; i++)
        if (Average (s[i]) > max)
            max = Average (s [i]);
    return max;
}

double PercentFizyka4or5( const Student* s, const int N)
{



    int k = 0;
    for ( int i = 0; i < N ; i++)
        if (s[i].fizyka == 5  || s[i].fizyka == 4)
            k++;
    return 100.0 * k / N;
}