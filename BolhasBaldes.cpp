#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int qtddMov = 0;

void printArray(int * A, int  size) {
  int  i;
  for (i = 0; i < size; i++) printf("%d ", A[i]);
  printf("\n");
}

void merge(int * array, int  e, int  m, int  d) {
  int  i, j, k;
  int  n1 = m - e + 1;
  int  n2 = d - m;
  int  E[n1], D[n2];

  for (i = 0; i < n1; i++) {
    E[i] = array[e + i];
  }
  for (j = 0; j < n2; j++) {
    D[j] = array[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = e;

  while (i < n1 && j < n2) {
    if (E[i] <= D[j]) {
      array[k] = E[i];
      i++;
    } else {
      array[k] = D[j];
      qtddMov += n1 - i;
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = E[i];
    i++;
    k++;
  }

  while (j < n2) {

    array[k] = D[j];
    j++;
    k++;
  }
}

void mergeSort(int * array, int  e, int  d) {
  if (e < d) {
    int  m = e + (d - e) / 2;
    // cout << "m = " << m << endl;

    mergeSort(array, e, m);
    mergeSort(array, m + 1, d);

    merge(array, e, m, d);

  }
}

int  main() {
  int  N;
  cin >> N;

  while (N != 0) {
    int * array = new int [N];

    for (int  i = 0; i < N; i++) {
      cin >> array[i];
    }

    mergeSort(array, 0, N-1);

    if ((qtddMov % 2) == 0) {
      cout << "Carlos" << endl;
    } else {
      cout << "Marcelo" << endl;
    }

    qtddMov = 0;

    delete[] array;
    cin >> N;
  }

  return 0;
}