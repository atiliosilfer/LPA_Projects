#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x >> y;
        cout << (__gcd(x, y)) << endl;
    }
    
    return 0;
}