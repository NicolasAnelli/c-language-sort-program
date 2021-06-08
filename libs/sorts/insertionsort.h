/*
 * insertionsort.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

void insertionSort(long* V, long N) {
  long i, j, aux;
  for(i=1; i<N; i++) {
    aux = V[i];
    for(j=i; (j>0) && (aux<V[j-1]); j--) {
      V[j] = V[j-1];
    }
      V[j] = aux;
  }
}

#endif /* INSERTIONSORT_H_ */