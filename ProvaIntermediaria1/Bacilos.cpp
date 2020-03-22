#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int fib[1501];

int fibonacci(){
    int a = 0, b = 1, c;
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 2; i < 1501; i++){
        c = (a + b) % 1000;
        fib[i] = c;
        a = b % 1000;
        b = c;
    }
    return 0;
}

int mod (string instante) {
    int resp = 0;

    for (int i = 0; i < instante.length(); i++){
        resp = ((resp*10) + (instante[i] - '0')) % 1500;
    }

    return resp;
}

int main()
{
    int numInstancias, pos;
    string instante;
    cin >> numInstancias;
    fibonacci();
        
    for (int i = 0; i < numInstancias; i++)
    {
        cin >> instante;
        pos = mod (instante);
        
        if (fib[pos] < 10)
        {
            cout << "00" << fib[pos]  << endl;
        }
        else if (fib[pos] < 100)
        {
            cout << '0' << fib[pos]  << endl;
        }
        else
        {
            cout << fib[pos]  << endl;
        }
    }

    return 0;
}