#include <iostream>

using namespace std;

string RemoverEspacos(string s)
{
    while (isspace(s[0])){
        s.erase(0, 1);
    }
    while (s[s.length() - 1] == ' '){
        s.pop_back();
    }

    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            i = i+1;
            while (s[i] == ' '){
                s.erase (i, 1);
            }
        }
    }

    return s;
}

int main()
{
    string *s = new string[100];
    int n;

    cin >> n;
    cin.ignore ();

    while (n != 0){
        getline (cin, s);
    }

    
    
    cout << '-' << s << '-' << endl;

    s = RemoverEspacos (s);

    cout << '-' << s << '-';
    
    return 0;
}