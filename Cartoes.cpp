#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
long long cards [10101];
long long sum [10101];

long long maiorSoma (long long N) {
    for (int i = N-1; i >=0; i--){
        for (int j = i+1; j < N; j++){
            cards[j] = sum[j] - sum[i-1] - min(cards[j-1], cards[j]);
        }
    }

    return cards[N-1];
}

void calcSum (long long N) {
    for (int i=1; i < N; i ++) {
        sum[i] = sum[i-1] + cards[i];
    }
}

int main()
{
    long long N;

    while (cin >> N){
        for (int i = 0; i < N; i++){
            cin >> cards[i];
        }

        sum[0] = cards[0];

        calcSum (N);

        cout << maiorSoma (N) << endl;
    }

    return 0;
}