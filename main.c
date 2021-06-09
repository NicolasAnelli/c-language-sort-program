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

#define SYSTEM_NAME "Analise de Algoritmos"
#define INITIAL_SIZE 20

/** Screen header **/
void header();

/** Main menu **/
void mainMenu();
void printMainMenu();

void loadingScreen();

void resultScreen(char* subtitle, long* vector, long size, char* time);
void printResultScreen(char* subtitle, long* vector, long size, char* time);

void configScreen();
void printConfigScreen();

long* regenerateVector();

/** Main program **/
long* _MAIN_VECTOR;
long _MAIN_VECTOR_SIZE = INITIAL_SIZE;
char _MAIN_VECTOR_TYPE = 'a';

int main() {
	_MAIN_VECTOR = regenerateVector();
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
				loadingScreen();
				stopwatchStart();
				selectionSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Selection sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '2':
				// Bubble sort
				loadingScreen();
				stopwatchStart();
				bubbleSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Bubble sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '3':
				// Insertion sort
				loadingScreen();
				stopwatchStart();
				insertionSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Insertion sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '4':
				// Merge sort
				loadingScreen();
				stopwatchStart();
				mergeSort(vector, 0, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Merge sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '5':
				// Quick sort
				loadingScreen();
				stopwatchStart();
				quickSort(vector, 0, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Quick sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '6':
				// Counting sort
				loadingScreen();
				stopwatchStart();
				countingSort(vector, _MAIN_VECTOR_SIZE);
				stopwatchStop();
				resultScreen("Counting sort", vector, _MAIN_VECTOR_SIZE, getStopwatchString());
				break;

			case '7':
				// Bucket sort
				setWarning("Não foi implementado XD");
				break;

			case '8':
				// Configurar vetor
				configScreen();
				break;

			case 'd':
			  // debug global var
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

void loadingScreen() {
	clearScreen();
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
			case 'd':
			  // debug
				clearScreen();
				printf("__MAIN_VECTOR: \n");
				imprimeVetor(_MAIN_VECTOR, _MAIN_VECTOR_SIZE);
				printf("\n");
				printf("vector: \n");
				imprimeVetor(vector, _MAIN_VECTOR_SIZE);
				printf("\n");
				printf("Digite qualquer valor para retornar: ");
				scanf(" %[^\n]", opt);
				break;
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
	emptyLine();
	line("0. Voltar", 'R');
	filledLine();
}

void configScreen() {
	long size;
	char *opt = (char*)malloc(sizeof(char));

	while (1) {
		clearScreen();
		printConfigScreen();
		printf("Escolha sua opcao: ");
		scanf(" %[^\n]", opt);

		switch(*opt) {
			case '1':
				free(_MAIN_VECTOR);
				_MAIN_VECTOR_TYPE = 'c';
				_MAIN_VECTOR = regenerateVector();
				setWarning("Vetor crescente gerado com sucesso");
				break;

			case '2':
				free(_MAIN_VECTOR);
				_MAIN_VECTOR_TYPE = 'd';
				_MAIN_VECTOR = regenerateVector();
				setWarning("Vetor decrescente gerado com sucesso");
				break;
				
			case '3':
				free(_MAIN_VECTOR);
				_MAIN_VECTOR_TYPE = 'a';
				_MAIN_VECTOR = regenerateVector();
				setWarning("Vetor aleatorio gerado com sucesso");
				break;

			case '4':
				clearScreen();
				printConfigScreen();
				printf("Digite o tamanho do novo vetor: ");
				if (scanf(" %ld", &size)) {
					free(_MAIN_VECTOR);
					_MAIN_VECTOR_SIZE = size;
					_MAIN_VECTOR = regenerateVector();
					setWarning("Novo vetor gerado com sucesso");
				}
				break;

			case 'd':
			  // debug
				clearScreen();
				printf("__MAIN_VECTOR: \n");
				imprimeVetor(_MAIN_VECTOR, _MAIN_VECTOR_SIZE);
				printf("\n");
				printf("Digite qualquer valor para retornar: ");
				scanf(" %[^\n]", opt);
				break;

			case '0':
				free(opt);
				return;
		}
	}
}
void printConfigScreen() {
	header();
	line("Configuracoes do vetor", 'C');
	emptyLine();
	line("1. Utilizar vetor crescente", 'L');
	emptyLine();
	line("2. Utilizar vetor decrescente", 'L');
	emptyLine();
	line("3. Gerar vetor aleatorio", 'L');
	emptyLine();
	line("4. Alterar tamanho do vetor", 'L');
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	emptyLine();
	line("0. Voltar", 'R');
	filledLine();
}

long* regenerateVector() {
	if (_MAIN_VECTOR_SIZE < 0) return _MAIN_VECTOR;

	switch(_MAIN_VECTOR_TYPE) {
		case 'a':
			return criaVetorAleatorio(_MAIN_VECTOR_SIZE);
		case 'c':
			return criaVetorCrescente(_MAIN_VECTOR_SIZE);
		case 'd':
			return criaVetorDecrescente(_MAIN_VECTOR_SIZE);
	}
}