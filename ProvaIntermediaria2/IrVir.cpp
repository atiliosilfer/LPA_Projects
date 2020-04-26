#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define WHITE 0  
#define GRAY 1
#define BLACK 2

int** createMatrix (int size, int numberOfEdge) {
    int** matrix = new int*[size];
    int vertex1,vertex2,P;


    for (int i = 0; i < size; i = i+1){
        matrix [i] = new int [size];
    }

    for (int i = 0; i < size; i = i+1){
        for (int j = 0; j < size; j = j+1){
            matrix [i][j] = 0;
        }
    }

    for (int i = 0; i < numberOfEdge; i = i+1){
            cin >> vertex1 >> vertex2 >> P;
            if (P == 1){
                matrix [vertex1 - 1][vertex2 - 1] = 1;
            } else {
                matrix [vertex1 - 1][vertex2 - 1] = 1;
                matrix [vertex2 - 1][vertex1 - 1] = 1;
            } 
    }

    return matrix;
}

int* createVector (int size){
    int* vector = new int[size];
    for (int i = 0; i < size; i = i+1){
        vector[i] = WHITE;
    }
    return vector;
}

int* clearVector (int* vector, int size) {
    for (int i = 0; i < size; i = i+1){
        vector[i] = WHITE;
    }
    return vector;
}

void DFS_VISIT (int u, int** matrix, int* vector, int size) {
    vector[u] = GRAY;
    for (int v = 0; v < size; v = v+1){
        if (matrix [u][v] == 1){
            if (vector [v] == WHITE) {
                DFS_VISIT (v, matrix, vector, size);
            }
        }        
    }
    vector [u] = BLACK;
}

bool DFS (int** matrix, int* vector, int size){
    int counter = 0;
    bool conexo = true;

    for (int i = 0; i < size; i = i+1){
        for (int u = i; u < size; u = u+1){
            if (vector[u] == WHITE){
                counter = counter + 1;
                DFS_VISIT (u, matrix, vector, size);
            }

            if (counter > 1){
                u = size;
                i = size;
                conexo = false;
            }
        }

        for (int k = 0; k < size; k++){
            if (vector[k] == WHITE)
                conexo = false;
        }

        clearVector (vector, size);
        counter = 0;
    }

    return conexo;
}


int main()
{
    int vertice, aresta;
    cin >> vertice >> aresta;
    int** matrix;
    int* vector;

    while (vertice != 0){
        matrix = createMatrix (vertice,aresta);
        vector = createVector (vertice);
        
        if (DFS (matrix, vector, vertice))
            cout << "1" << endl;
        else 
            cout << "0" << endl;

        cin >> vertice >> aresta;
    }

    return 0;
}