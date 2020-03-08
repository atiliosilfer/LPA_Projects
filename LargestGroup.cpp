<<<<<<< HEAD
#include <iostream>
#include <cmath>
#include <iomanip> 
#include <string.h>

#define WHITE 0  
#define GRAY 1
#define BLACK 2

using namespace std;

int** createMatrix (int size, int numberOfEdge) {
    int** matrix = new int*[size];
    int vertex1, vertex2;

    for (int i = 0; i < size; i = i+1){
        matrix [i] = new int [size];
    }

    for (int i = 0; i < size; i = i+1){
        for (int j = 0; j < size; j = j+1){
            matrix [i][j] = 0;
        }
    }

    for (int i = 0; i < numberOfEdge; i = i+1){
            cin >> vertex1 >> vertex2;
            matrix [vertex1 - 1][vertex2 - 1] = 1;
            matrix [vertex2 - 1][vertex1 - 1] = 1;
    }

    return matrix;
}

int* createVector (int size, int null){
    int* vector = new int[size];
    for (int i = 0; i < size; i = i+1){
        vector[i] = null;
    }
    return vector;
}

/**
 * Percorre matriz de adjacencias
 */
int* DFS_VISIT (int u, int** matrix, int* vector, int size, int* vectorPrint) {
    vector[u] = GRAY;                                                //seta que vertice já foi visitado
    vectorPrint [u] = u;                                             //coloca vertice no array para ser mostrado posteriormente
    for (int v = 0; v < size; v = v+1){
        if (matrix [u][v] == 1){                                     //caso tenha arestas entre os vertices
            if (vector [v] == WHITE) {                               //verifica se o vertice ainda nao foi visitado
                DFS_VISIT (v, matrix, vector, size, vectorPrint);    //vai para o proximo vertice e continua a busca
            }
        }        
    }
    vector [u] = BLACK;                                              //ao sair do vertice colore ele de preto para mostrar q todo o componente já foi visitado
    return vectorPrint;
}

/**
 * Algoritmo de busca em profundidade
 */
void DFS (int** matrix, int* vector, int size){
    int counter = 0, SUM = 0;

    for (int u = 0; u < size; u = u+1){
        if (vector[u] == WHITE){                                        //se o vetor ainda nao for visitado
            int* vectorPrint = createVector(size, -1);                  //vetor auxiliar para printar vertices de cada componente
            DFS_VISIT (u, matrix, vector, size, vectorPrint);           //percorre matriz de adjacencias

            for(int i = 0; i < size; i++){                              
                if(vectorPrint [i] != -1){
                    counter++;          
                }
            }

            if (counter > SUM){
                SUM = counter;
            }

            counter = 0;
        }
    }
    cout << SUM << endl;
}


int main () {
    int N,V,E;
    cin >> N;

    for (int i = 0; i < N; i = i+1){
        cin >> V >> E;
        int** matrix = createMatrix (V,E);
        int* vector = createVector (V, WHITE);
        DFS (matrix, vector, V);
    }
=======
#include <iostream>
#include <cmath>
#include <iomanip> 
#include <string.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int** createMatrix (int size, int numberOfEdge) {
    int** matrix = new int*[size];
    int vertex1, vertex2;

    for (int i = 0; i < size; i = i+1){
        matrix [i] = new int [size];
    }

    for (int i = 0; i < size; i = i+1){
        for (int j = 0; j < size; j = j+1){
            matrix [i][j] = 0;
        }
    }

    for (int i = 0; i < numberOfEdge; i = i+1){
            cin >> vertex1 >> vertex2;
            matrix [vertex1 - 1][vertex2 - 1] = 1;
            matrix [vertex2 - 1][vertex1 - 1] = 1;
    }

    return matrix;
}

int* createVector (int size, int null){
    int* vector = new int[size];
    for (int i = 0; i < size; i = i+1){
        vector[i] = null;
    }
    return vector;
}

/**
 * Percorre matriz de adjacencias
 */
int* DFS_VISIT (int u, int** matrix, int* vector, int size, int* vectorPrint) {
    vector[u] = GRAY;                                                //seta que vertice já foi visitado
    vectorPrint [u] = u;                                             //coloca vertice no array para ser mostrado posteriormente
    for (int v = 0; v < size; v = v+1){
        if (matrix [u][v] == 1){                                     //caso tenha arestas entre os vertices
            if (vector [v] == WHITE) {                               //verifica se o vertice ainda nao foi visitado
                DFS_VISIT (v, matrix, vector, size, vectorPrint);    //vai para o proximo vertice e continua a busca
            }
        }        
    }
    vector [u] = BLACK;                                              //ao sair do vertice colore ele de preto para mostrar q todo o componente já foi visitado
    return vectorPrint;
}

/**
 * Algoritmo de busca em profundidade
 */
void DFS (int** matrix, int* vector, int size){
    int counter = 0, SUM = 0;

    for (int u = 0; u < size; u = u+1){
        if (vector[u] == WHITE){                                        //se o vetor ainda nao for visitado
            int* vectorPrint = createVector(size, -1);                  //vetor auxiliar para printar vertices de cada componente
            DFS_VISIT (u, matrix, vector, size, vectorPrint);           //percorre matriz de adjacencias

            for(int i = 0; i < size; i++){                              
                if(vectorPrint [i] != -1){
                    counter++;          
                }
            }

            if (counter > SUM){
                SUM = counter;
            }

            counter = 0;
        }
    }
    cout << SUM << endl;
}


int main () {
    int N,V,E;
    cin >> N;

    for (int i = 0; i < N; i = i+1){
        cin >> V >> E;
        int** matrix = createMatrix (V,E);
        int* vector = createVector (V, WHITE);
        DFS (matrix, vector, V);
    }
>>>>>>> 705adfa79f9ab9456e19f898e9c7a564195c4570
}