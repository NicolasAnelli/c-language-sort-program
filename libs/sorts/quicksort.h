/*
 * quicksort.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

void quickSort(long *V, long inicio, long fim);
long particiona(long *V, long inicio, long fim);

void quickSort(long *V, long inicio, long fim) {
  long pivo;
  if (fim > inicio) {
    pivo = particiona(V, inicio, fim);
    quickSort(V, inicio, pivo-1);
    quickSort(V, pivo+1, fim);
  }
}
long particiona(long *V, long inicio, long fim) {
  long esq, dir, pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = V[inicio];
  while (esq < dir) {
    while (esq <= fim && V[esq] <= pivo)
      esq++;
    while (dir >= 0 && V[dir] > pivo) 
      dir--;
    if (esq < dir) {
      aux = V[esq];
      V[esq] = V[dir];
      V[dir] = aux;
    }
  }
  V[inicio] = V[dir];
  V[dir] = pivo;
  return dir;
}

#endif /* QUICKSORT_H_ */