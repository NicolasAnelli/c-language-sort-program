#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "libs/helpers/layout.h"
#include "libs/helpers/stopwatch.h"
#include "libs/helpers/warning.h"
#include "libs/helpers/util.h"

#include "libs/sorts/bubblesort.h"
#include "libs/sorts/countingsort.h"
#include "libs/sorts/insertionsort.h"
#include "libs/sorts/mergesort.h"
#include "libs/sorts/quicksort.h"
#include "libs/sorts/selectionsort.h"

#define SYSTEM_NAME "Projeto Final - Analise de Algoritmos"
#define INITIAL_SIZE 25

/** Screen header **/
void header();

/** Main menu **/
void mainMenu();
void printMainMenu();

void printLoadingScreen();

void resultScreen(char* subtitle, long* vector, long size, char* time);
void printResultScreen(char* subtitle, long* vector, long size, char* time);

/** Main program **/
long* _MAIN_VECTOR;
long _MAIN_VECTOR_SIZE;
int main() {
	_MAIN_VECTOR = criaVetorAleatorio(INITIAL_SIZE);
	_MAIN_VECTOR_SIZE = INITIAL_SIZE;
	mainMenu();
	clearScreen();
	return EXIT_SUCCESS;
}

/** Implementations **/
void header() {
	char *aux = (char*)malloc(80*sizeof(char));
	filledLine();
	line(SYSTEM_NAME, 'C');
	sprintf(aux, "Tamanho vetor atual: %lu", _MAIN_VECTOR_SIZE);
	line(aux, 'R');
	filledLine();
	aux = popWarning();
	if(strcmp(aux, "")) {
		line(aux, 'C');
	} else {
		emptyLine();
	}
}

void mainMenu() {
	char *opt = (char*)malloc(sizeof(char));
	long* vector;
	while (1) {
		clearScreen();
		printMainMenu();
		printf("Escolha sua opcao: ");
		scanf(" %[^\n]", opt);

		vector = copiarVetor(_MAIN_VECTOR, _MAIN_VECTOR_SIZE);

		switch(*opt) {
			case '1':
				// Selection sort
				printLoadingScreen();
				stopwatchStart();
				selectionSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Selection sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '2':
				// Bubble sort
				printLoadingScreen();
				stopwatchStart();
				bubbleSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Bubble sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '3':
				// Insertion sort
				printLoadingScreen();
				stopwatchStart();
				insertionSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Insertion sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '4':
				// Merge sort
				printLoadingScreen();
				stopwatchStart();
				mergeSort(vector, 0, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Merge sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '5':
				// Quick sort
				printLoadingScreen();
				stopwatchStart();
				quickSort(vector, 0, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Quick sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '6':
				// Counting sort
				printLoadingScreen();
				stopwatchStart();
				countingSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Counting sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '7':
				// Bucket sort
				// Não foi implementado XD
				break;

			case '8':
				// Configurar vetor
				break;

			case 'a':
			  // Trigger auto test
				break;

			case 's':
			  // See actual vector
				clearScreen();
				printf("__MAIN_VECTOR: \n");
				imprimeVetor(_MAIN_VECTOR, _MAIN_VECTOR_SIZE);
				printf("\n");
				printf("vector: \n");
				imprimeVetor(vector, _MAIN_VECTOR_SIZE);
				printf("Digite qualquer valor para retornar: ");
				scanf(" %[^\n]", opt);
				break;

			case '0':
					free(opt);
					return;
		}
	}
}
void printMainMenu() {
	header();
	line("1. Selection Sort", 'L');
	emptyLine();
	line("2. Bubble Sort", 'L');
	emptyLine();
	line("3. Insertion Sort", 'L');
	emptyLine();
	line("4. Merge Sort", 'L');
	emptyLine();
	line("5. Quick Sort", 'L');
	emptyLine();
	line("6. Counting Sort", 'L');
	emptyLine();
	line("7. Bucket Sort (Indisponível)", 'L');
	emptyLine();
	line("8. Configurar vetor", 'L');
	emptyLine();
	line("0. Sair", 'R');
	filledLine();
}

void printLoadingScreen() {
	header();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	line("Carregando...", 'C');
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	filledLine();
	printf("Aguarde...");
}

void resultScreen(char* subtitle, long* vector, long size, char* time) {
	char *opt = (char*)malloc(sizeof(char));
	while (1) {
		clearScreen();
		printResultScreen(subtitle, vector, size, time);
		printf("Escolha sua opcao: ");
		scanf(" %[^\n]", opt);

		switch(*opt) {
			case '0':
				free(opt);
				return;
		}
	}
}
void printResultScreen(char* subtitle, long* vector, long size, char* time) {
	char *aux = (char*)malloc(80*sizeof(char));
	long random = rand() % size;
	header();
	line(subtitle, 'C');
	emptyLine();
  sprintf(aux, "Tamanho do vetor: %lu elementos", size);
	line(aux, 'L');
	emptyLine();
	sprintf(aux, "Tempo de execucao: %s", time);
	line(aux, 'L');
	emptyLine();
	line("Amostras", 'L');
	emptyLine();
	sprintf(aux, " > Primeiro elemento: %lu", vector[0]);
	line(aux, 'L');
	emptyLine();
	sprintf(aux, " > Elemento central: %lu", vector[(int)(size/2)]);
	line(aux, 'L');
	emptyLine();
	sprintf(aux, " > Ultimo elemento: %lu", vector[size-1]);
	line(aux, 'L');
	emptyLine();
	sprintf(aux, " > Elemento aleatorio [pos: %lu]: %lu", random, vector[random]);
	line(aux, 'L');
	line("0. Voltar", 'R');
	emptyLine();
	filledLine();
}