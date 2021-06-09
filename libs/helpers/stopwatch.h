/*
 * stopwatch.h
 *
 *  Created on: Jun 8, 2021
 *      Author: nicolasanelli
 */
#include <stdlib.h>
#include <time.h>

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

clock_t _BEGIN, _END;

void stopwatchStart();
void stopwatchStop();
double getStopwatchMicroseconds();
char* getStopwatchString();

void stopwatchStart() {
  _BEGIN = clock();
  _END = _BEGIN;
}
void stopwatchStop() {
  _END = clock();
}
double getStopwatchMicroseconds() {
  return (double)(_END - _BEGIN) / CLOCKS_PER_SEC * 1000 * 1000;
}
char* getStopwatchString() {
	char *aux = (char*)malloc(20*sizeof(char));
  char *unit = (char*)malloc(2*sizeof(char));
  double time_spent = getStopwatchMicroseconds();
  if (time_spent < 1000) unit = "us";
  if (time_spent >= 1000 && time_spent < 1000*1000) { unit = "ms"; time_spent /= 1000; }
  if (time_spent >= 1000*1000 ) { unit = "s"; time_spent /= (1000*1000); } 
  sprintf(aux, "%.4f%s", time_spent, unit);
  return aux;
}

#endif /* STOPWATCH_H_ */