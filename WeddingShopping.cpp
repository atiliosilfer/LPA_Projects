#include <bits/stdc++.h>

#include <iostream>
#include <string>

using namespace std;

int numTests, maxMoney, numGarments;
int matrix[20][20];
int aux[200][20];

void showMatrix() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

void setarValorM() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      aux[i][j] = -1;
    }
  }
}

void setarValorA() {
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 20; j++) {
      aux[i][j] = -1;
    }
  }
}

int maiorCompra(int money, int numItem) {
  if (money < 0) {
    return -1;
  }

  if (numItem == numGarments) {
    return maxMoney - money;
  }

  if (aux[money][numItem] != -1) {
    return aux[money][numItem];
  }

  int resp = -1;

  for (int i = 0; i < matrix[numItem][0]; i++) {
    resp =
        max(resp, maiorCompra((money - matrix[numItem][i + 1]), numItem + 1));
  }

  return aux[money][numItem] = resp;
}

int main() {
  cin >> numTests;

  for (int i = 0; i < numTests; i++) {
    cin >> maxMoney >> numGarments;

    for (int j = 0; j < numGarments; j++) {
      cin >> matrix[j][0];
      for (int k = 1; k < matrix[j][0] + 1; k++) {
        cin >> matrix[j][k];
      }
    }

    setarValorA();
    setarValorM();

    int answ = maiorCompra(maxMoney, 0);

    if (answ > 0) {
      cout << answ << endl;
    } else {
      cout << "no solution" << endl;
    }
  }

  return 0;
}

