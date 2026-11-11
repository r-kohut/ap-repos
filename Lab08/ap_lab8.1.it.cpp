#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool Contains( const char* str)
{
for (int i = 0; str[i] != '\0'; i++)
    if (str [i] == '*' && str [i + 1] == '*' && str [i + 2 ] == '*')
    return true;
return false;
}

char* Change(char* str)
{
    char* tmp = new char[strlen( str) + 1];
    char* t = tmp;
    int i = 0;
    while ( str [i] != '\0')
        if (str [i] == '*' && str [i + 1] == '*' && str [i + 2 ] == '*')
           {*t++ = '!';
            *t++ = '!';
            i += 3;   // скіпаєм ті три зірочки 
           }
        else
           *t ++ = str [i++ ];
    
    *t = '\0';
            
    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str [ 100 ];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    if (Contains(str))
    {
        cout << "The string contains '***'" << endl;
    }
    else
    {
        cout << "The string does not contain '***'." << endl;
    }

    char* dest = Change (str);

    cout << "Modified string (param):" << str << endl;
    cout << "Modified string (result):" << dest << endl;

    delete[] dest;
    return 0;
}