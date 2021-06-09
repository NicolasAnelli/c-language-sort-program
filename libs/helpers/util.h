/*
 * util.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#include <stdlib.h>
#include <time.h>

#ifndef UTIL_H_
#define UTIL_H_

long* criaVetorCrescente(long size) {
  long i;
  long* v;

  v = malloc(sizeof(long) * size);
  for(i=0; i<size; i++) {
    v[i] = i;
  }
  return v;
}
long* criaVetorDecrescente(long size) {
  long i;
  long* v;

  v = malloc(sizeof(long) * size);
  for(i=0; i<size; i++) {
    v[i] = size-i;
  }
  return v;
}
long* criaVetorAleatorio(long size) {
  srand(time(0));

  long i;
  long* v;

  v = malloc(sizeof(long) * size);
  for(i=0; i<size; i++) {
    v[i] = (rand() % size);
  }
  return v;
}

long* copiarVetor(long *V, long N) {
  long i;
  long* newV;

  newV = malloc(sizeof(long) * N);
  for(i=0; i<N; i++) {
    newV[i] = V[i];
  }
  return newV;
}

void imprimeVetor(long *V, long N) {
  long i;
  for(i=0; i<N; i++) {
    printf("%lu, ", V[i]);
  }
  printf("\n");
}

#endif /* UTIL_H_ */