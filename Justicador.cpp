#include <iostream>
#include <string>

using namespace std;

string RemoverEspacos(string s){
    while (isspace(s[0])){
        s.erase(0, 1);
    }

    while (isspace(s[s.length() - 1])){
        s.pop_back();
    }

    for (int i = 0; i < s.length(); i++){
        if (isspace(s[i])){
            i = i+1;
            while (isspace(s[i])){ 
                s.erase (i, 1);
            }
        }
    }
    
    return s;
}

void JustificaString (string s, int qtddEspacos){
    for (int i = 0; i < qtddEspacos; i++){
        cout << ' ';
    }
    cout << s << "\n";
}

int main(){
    int n;
    int maiorString = 0;

    cin >> n;

    while (n > 0){
        cin.ignore ();

        string *s = new string[n];
        for (int i = 0; i < n; i++){
            getline (cin, s[i]);
            s[i] = RemoverEspacos (s[i]);
            if (s[i].length() > maiorString){
                maiorString = s[i].length();
            }
        }
        
        for (int i = 0; i < n; i++){
            JustificaString (s[i], maiorString-s[i].length());
        }
        
        delete[] s;

        cin >> n;
        if (n != 0){
            cout << "\n";
            maiorString = 0;
        }
    }
    return 0;
}