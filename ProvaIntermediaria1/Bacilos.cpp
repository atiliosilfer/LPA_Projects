#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


int fibonacci(int n) 
{ 
    if (n <= 1) 
        return n;

    n = n%1000;
     
    return fibonacci(n-1) + fibonacci(n-2); 
} 

int main()
{
    int numInstancias, instante;
    cin >> numInstancias;

    for (int i = 0; i < numInstancias; i++) {
        cin >> instante;
        instante = fibonacci (instante);
        cout << instante << endl;
    }
    return 0;
}
