#include <iostream>
#include <string>
#include <bits/stdc++.h>

#define infinity 1000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int* createVector (int size, int pattern) {
    int* vector = new int[size];
    for (int i = 0; i < size; i = i+1){
        vector[i] = pattern;
    }
    return vector;
}

int** createMatrix (int numVertex, int numEdge, int pattern) {
    int** matrix = new int*[numVertex];
    int city1, city2, distance;

    for (int i = 0; i < numVertex; i = i+1){
        matrix [i] = new int [numVertex];
    }

    for (int i = 0; i < numVertex; i = i+1){
        for (int j = 0; j < numVertex; j = j+1){
            matrix [i][j] = pattern;
        }
    }

    for (int i = 0; i < numEdge; i++){
        cin >> city1 >> city2 >> distance;

        if (matrix [city1][city2] != pattern){
            if (matrix [city1][city2] > distance){
                matrix [city1][city2] = distance;
                matrix [city2][city1] = distance;    
            }
        } else {
            matrix [city1][city2] = distance;
            matrix [city2][city1] = distance;
        }
    }

    return matrix;
}

int *createVectorInt(int size)
{
    int *vector = new int[size];
    for (int i = 0; i < size; i = i + 1)
    {
        vector[i] = i;
    }
    return vector;
}

int MST_PRIM(int **matrix, int size)
{
    int min, aux, aux2; //min = menor distancia entre os vertices
    int u = 0;          //u = vetor inicial
    int n = size;
    int answ = 0;                                     //sum = distancia do menor caminho
    int *chave = createVector(size, infinity);                //BUILD-MIN-HEAP - distancia
    int *Vector = createVectorInt(size);                //BUILD-MIN-HEAP - auxiliar (numero do vertice no Heap, auxiliar na busca de matriz de adjacencias)
    chave[0] = 0;                                       //distancia 0 entre o vertice inicial do Heap e ele mesmo

    while (n > 0)
    { //enquanto nao ligar todos os vertices
        
        if (answ < chave[0])
            answ = chave[0];

        Vector[0] = Vector[n - 1]; //tira o primeiro vertice e substitue pelo ultimo
        chave[0] = chave[n - 1];   //tira o primeiro vertice e substitue pelo ultimo
        n--;                       //diminue o tamanho do Heap (logicamente)

        for (int i = 0; i < n; i++)
        {
            if (chave[i] > matrix[u][Vector[i]])
            {
                chave[i] = matrix[u][Vector[i]]; //atualiza distancias do Heap
            }
        }

        for (int i = 0; i < n - 1; i++)
        { //Reordenar Heap
            min = i;
            for (int j = (i + 1); j < n; j++)
            {
                if (chave[j] < chave[min])
                    min = j;
            }

            if (chave[i] != chave[min])
            {
                aux = chave[i];
                chave[i] = chave[min];
                chave[min] = aux;
                aux2 = Vector[i];
                Vector[i] = Vector[min];
                Vector[min] = aux2;
            }
        }
        u = Vector[0]; //pega o primeiro do Heap
    }

    return answ;
}

int main() {
    int numCities, numRoads, answ;
    cin >> numCities >> numRoads;

    while (numCities != 0) {
        
        int **graph = createMatrix(numCities, numRoads, infinity);
        answ = MST_PRIM (graph, numCities);

        if (answ == 1000000){
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << answ << endl; 
        }

        cin >> numCities >> numRoads;
    }
}