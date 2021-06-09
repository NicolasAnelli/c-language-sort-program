/*
 * warning.h
 *
 *  Created on: Oct 16, 2020
 *      Author: nicolasanelli
 */
#include <stdio.h>
#include "layout.h"

#ifndef WARNING_H_
#define WARNING_H_

char _warning[78];
void setWarning(char* msg) {
	strcpy(_warning, msg);
}
char* popWarning() {
	char *aux = (char*)malloc(78*sizeof(char));
  strcpy(aux, _warning);
	strcpy(_warning, "");
  return aux;
}

#endif /* WARNING_H_ */

















