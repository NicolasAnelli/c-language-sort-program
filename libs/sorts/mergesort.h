/*
 * mergesort.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#ifndef MERGESORT_H_
#define MERGESORT_H_

void mergeSort(long *V, long inicio, long fim) {
  long meio;
  if (inicio < fim) {
    meio = floor((inicio+fim)/2);
    mergeSort(V, inicio, meio);
    mergeSort(V, meio+1, fim);
    merge(V, inicio, meio, fim);
  } 
}
void merge(long *V, long inicio, long meio, long fim) {
  long *temp, p1, p2, tamanho, i, j, k;
  long fim1 = 0, fim2 = 0;
  
  tamanho = fim - inicio + 1;
  p1 = inicio;
  p2 = meio + 1;
  temp = (long *) malloc(tamanho * sizeof(long));
  if (temp != NULL) {
    for (i=0; i<tamanho; i++) {
      if (!fim1 && !fim2) {
        if (V[p1] < V[p2]) {
          temp[i] = V[p1++];
        } else {
          temp[i] = V[p2++];
        }
        if (p1 > meio) fim1 = 1;
        if (p2 > fim) fim2 = 1;
      } else {
        if (!fim1) {
          temp[i] = V[p1++];
        } else {
          temp[i] = V[p2++];
        }
      }
    }
    for (j=0, k=inicio; j<tamanho; j++, k++) {
      V[k] = temp[j];
    }
  }
  free(temp);
}

#endif /* MERGESORT_H_ */