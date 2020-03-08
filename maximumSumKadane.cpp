#include <iostream>

using namespace std;

int AcharMaiorSomaArrayKadane (int* array, int tam) {
    int maiorSoma = array[0], soma = 0; 
  
    for (int i = 0; i < tam; i++) 
    { 
        soma = soma + array[i]; 
        if (maiorSoma < soma) 
            maiorSoma = soma; 
  
        if (soma < 0) 
            soma = 0; 
    } 
    return maiorSoma; 
}

void PreencherMatriz (int** matrix, int tam) {
    for (int i = 0; i < tam; i++){      
        for (int j = 0; j < tam; j++){
            cin >> matrix [i][j];
        }
    }
}

void ZerarArray (int* array, int tam){
  for (int i = 0; i < tam; i++) {
    array[i] = 0;
  }  
}

int main () {
  int tam;
  int soma, maiorSoma;

  cin >> tam;
  int **matrix = new int*[tam];  
  int *array = new int[tam];

  for (int i = 0; i < tam; i++) {
    array[i] = 0;
    matrix [i] = new int [tam];
  }

  PreencherMatriz (matrix, tam);
  maiorSoma = matrix [0][0];

  for (int i = 0; i < tam; i++){
    ZerarArray (array, tam); 
    for (int j = i; j < tam; j++){
      for (int k = 0; k < tam; k++){
          array[k] = array[k] + matrix[j][k];
      }
      soma = AcharMaiorSomaArrayKadane(array, tam); 

      if (soma > maiorSoma )
        maiorSoma = soma;
    }
  }

  cout << maiorSoma;

  return 0;
}
