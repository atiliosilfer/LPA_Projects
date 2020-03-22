#include <iostream>
#include <string>

#define infinity 999999
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int *createVector(int size, int null)
{
    int *vector = new int[size];
    for (int i = 0; i < size; i = i + 1)
    {
        vector[i] = null;
    }
    return vector;
}

string *CreateVectorStations(int numStations)
{
    string *stationsVector = new string[numStations];

    for (int i = 0; i < numStations; i++)
    {
        cin >> stationsVector[i];
    }

    return stationsVector;
}

int **CreateMatrix(int numConections, int numStations, string *stationsVector)
{
    string station1, station2;
    int x, y; //posicao das estações no array
    int dist;

    int **matrix = new int *[numStations];
    for (int i = 0; i < numStations; i = i + 1)
    {
        matrix[i] = new int[numStations];
    }

    for (int i = 0; i < numStations; i = i + 1)
    {
        for (int j = 0; j < numStations; j = j + 1)
        {
            matrix[i][j] = infinity;
        }
    }

    for (int i = 0; i < numConections; i++)
    {
        cin >> station1;
        cin >> station2;
        cin >> dist;

        for (int j = 0; j < numStations; j = j + 1)
        {
            if (stationsVector[j] == station1)
                x = j;
            else if (stationsVector[j] == station2)
                y = j;
        }

        if (matrix[x][y] != 0)
        {
            if (matrix[x][y] > dist)
            {
                matrix[x][y] = dist;
                matrix[y][x] = dist;
            }
        }
        else
        {
            matrix[x][y] = dist;
            matrix[y][x] = dist;
        }
    }

    return matrix;
}

void showMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        cout << endl
             << "| ";
        for (int j = 0; j < size; j = j + 1)
        {
            cout << matrix[i][j] << " | ";
        }
    }
}

double *createVectorDouble(int size, double null)
{
    double *vector = new double[size];
    for (int i = 0; i < size; i = i + 1)
    {
        vector[i] = null;
    }
    return vector;
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

void MST_PRIM(int **matrix, int size)
{
    int min, aux, aux2; //min = menor distancia entre os vertices
    int u = 0;          //u = vetor inicial
    int n = size;
    double sum = 0;                                     //sum = distancia do menor caminho
    double *chave = createVectorDouble(size, infinity); //BUILD-MIN-HEAP - distancia
    int *Vector = createVectorInt(size);                //BUILD-MIN-HEAP - auxiliar (numero do vertice no Heap, auxiliar na busca de matriz de adjacencias)
    chave[0] = 0;                                       //distancia 0 entre o vertice inicial do Heap e ele mesmo

    while (n > 0)
    { //enquanto nao ligar todos os vertices
        sum = sum + chave[0];
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
    if (sum > infinity-1){
        cout << "Impossible" << endl;
    } else {
        cout << sum << endl;
    }

}

int main()
{
    int numStations, numConections;

    int *vector;

    cin >> numStations;
    cin >> numConections;

    while (numStations != 0 && numConections != 0)
    {
        string *stationsVector = CreateVectorStations(numStations);
        int **matrix = CreateMatrix(numConections, numStations, stationsVector);
        string vectorInicial;
        cin >> vectorInicial;
 
        MST_PRIM(matrix, numStations);

        cin >> numStations;
        cin >> numConections;
    }
}