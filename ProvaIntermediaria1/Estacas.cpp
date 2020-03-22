#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,perimetro;
    int resp = 0;

    while (cin >> x >> y){
        perimetro = x*2 + y*2;

        resp = perimetro/(__gcd(x, y));

        cout << resp << endl;
    }
    
    return 0;
}