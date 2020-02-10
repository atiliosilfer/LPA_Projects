#include <iostream>

using namespace std;

int main ()
{
  int tam;
  int sum;

  cin >> tam;
  int **matrix = new int*[tam];  

  for (int i = 0; i < tam; i++) {
      matrix [i] = new int [tam];
  }

//Preenche matriz
  for (int i = 0; i < tam; i++){      
    for (int j = 0; j < tam; j++){
        cin >> matrix [i][j];
    }
  }

//
  for (int i = 0; i < tam; i++){      
    for (int j = 0; j < tam; j++){
        
    }
  }
}