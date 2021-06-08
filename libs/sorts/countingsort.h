/*
 * countingsort.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#ifndef COUNTINGSORT_H_
#define COUNTINGSORT_H_

void countingSort(long* V, long N) {
  int i, j, k;
  int *baldes = malloc(sizeof(long) * N);
  for (i=0; i<N; i++) {
    baldes[i] = 0;
  }
  for (i=0; i<N; i++) {
    baldes[V[i]]++;
  }

  for (i=0, j=0; j<N; j++) {
    for (k=baldes[j]; k>0; k--) {
      V[i++] = j;
    }
  }

  free(baldes);
}

#endif /* COUNTINGSORT_H_ */