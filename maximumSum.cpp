#include <iostream>

using namespace std;

int AcharMaiorSomaArray (int* array, int tam) {
    int soma = array[0];
    int maiorSoma = array[0];

    for (int i = 1; i < tam; i++){
        if (soma + array[i] < array[i]){
            soma = array[i];
        } else {
            soma = soma + array[i];
        }

        if (maiorSoma < soma){
            maiorSoma = soma;
        }
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
      soma = AcharMaiorSomaArray(array, tam); 

      if (soma > maiorSoma )
        maiorSoma = soma;
    }
  }

  cout << maiorSoma;

  return 0;
}
