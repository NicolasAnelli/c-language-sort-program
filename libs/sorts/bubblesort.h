/*
 * bubblesort.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

void bubbleSort(long* V, long N);

void bubbleSort(long* V, long N) {
  long i, continua, aux, fim = N;
  do {
    continua = 0;
    for (i=0; i<fim-1; i++) {
      if (V[i] > V[i+1]) {
        aux = V[i];
        V[i] = V[i+1];
        V[i+1] = aux;
        continua = i;
      }
    }
    fim--;
  } while (continua != 0);
}

#endif /* BUBBLESORT_H_ */