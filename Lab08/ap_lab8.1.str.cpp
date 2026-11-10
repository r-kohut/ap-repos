#include <iostream>
#include <string>
using namespace std;

//повертає тру якщо в рядку є ***
bool Contains(const string s)
{
    return s.find("***") != string :: npos;
}

// Замінює кожну трійку "***" парою "!!".
// Результат повертається і як значення функції, і через параметр s
string Change(string& s)
{
    size_t pos = 0; 
    while ((pos = s.find("***", pos)) != string::npos)
    {
        s.replace(pos, 3, "!!!"); // 3 символи замінюються на !!
        pos += 2; // скіпаємо вставлені !!
    }
 return s;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (Contains(str))
    {
        cout << "The string contains '***'" << endl;
        cout << "Modified string: " << Change(str) << endl;
    }
    else
    {
        cout << "The string does not contain '***'." << endl;
    }

    string dest = Change (str);
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}

