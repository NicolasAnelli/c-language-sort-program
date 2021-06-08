/*
 * selectionsort.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

void selectionSort(long* V, long N);

void selectionSort(long* V, long N) {
  long i, j, menor_i, troca;
  for (i=0; i<N-1; i++) {
    menor_i = i;
    for (j=i+1; j<N; j++) {
      if (V[j] < V[menor_i])
        menor_i = j;
    }
    if (i != menor_i) {
      troca = V[i];
      V[i] = V[menor_i];
      V[menor_i] = troca;
    }
  }
}

#endif /* SELECTIONSORT_H_ */