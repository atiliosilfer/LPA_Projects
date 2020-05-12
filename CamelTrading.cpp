#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> operadores;
vector<long long int> numbers;
vector<char> operadores1;
vector<long long int> numbers1;

int findOP (char c) {
  int pos = -1, tam = operadores.size();
  
  for (int i = 0; i < tam; i++){
    if (operadores[i] == c){
      pos = i;
      i = tam;
    }
  }
  return pos;
}

int findOP1 (char c) {
  int pos = -1, tam = operadores1.size();
  
  for (int i = 0; i < tam; i++){
    if (operadores1[i] == c){
      pos = i;
      i = tam;
    }
  }
  return pos;
}

long long int maxResult() {
  long long int answ = 0;
  int pos = -1;

  pos = findOP ('+');

  while (pos != -1){
    answ = numbers [pos] + numbers[pos+1];
    numbers[pos] = answ;
    numbers.erase (numbers.begin()+(pos+1));
    operadores.erase(operadores.begin()+pos);
    pos = findOP ('+');
  }

  pos = findOP ('*');

  while (pos != -1){
    answ = numbers [pos] * numbers[pos+1];
    numbers[pos] = answ;
    numbers.erase (numbers.begin()+(pos+1));
    operadores.erase(operadores.begin()+pos);
    pos = findOP ('*');
  }

  return answ;
}

long long int minResult() {
  long long int answ = 0;
  int pos = -1;

  pos = findOP1 ('*');

  while (pos != -1){
    answ = numbers1 [pos] * numbers1[pos+1];
    numbers1[pos] = answ;
    numbers1.erase (numbers1.begin()+(pos+1));
    operadores1.erase(operadores1.begin()+pos);
    pos = findOP1 ('*');
  }

  pos = findOP1 ('+');

  while (pos != -1){
    answ = numbers1 [pos] + numbers1[pos+1];
    numbers1[pos] = answ;
    numbers1.erase (numbers1.begin()+(pos+1));
    operadores1.erase(operadores1.begin()+pos);
    pos = findOP1 ('+');
  }

  return answ;
}

int main() {
  int N;
  long long int num;
  char op;

  cin >> N;

  while (N > 0) {
    do {
      scanf("%lld", &num);
      numbers.push_back(num);
      numbers1.push_back(num);

      scanf("%c", &op);
      operadores.push_back(op);
      operadores1.push_back(op);


    } while (op != '\n');

    if (numbers.size() != 1){
      cout << "The maximum and minimum are " << maxResult() << " and " << minResult() << "." << endl;
    } else {
      cout << "The maximum and minimum are " << numbers[0] << " and " << numbers[0] << "." << endl;
    }

    numbers.clear();
    numbers1.clear();
    operadores.clear();
    operadores1.clear();
    N--;
  }

  return 0;
}