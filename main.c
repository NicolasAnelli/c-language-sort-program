#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "libs/util/layout.h"
#include "libs/util/warning.h"
#include "libs/util/util.h"

#include "libs/sorts/bubblesort.h"
#include "libs/sorts/countingsort.h"
#include "libs/sorts/insertionsort.h"
#include "libs/sorts/mergesort.h"
#include "libs/sorts/quicksort.h"
#include "libs/sorts/selectionsort.h"

#define SYSTEM_NAME "Projeto Final - Analise de Algoritmos"
#define TAMANHO_INICIAL 25000

/** Screen header **/
void header();

/** Main menu **/
void mainMenu();
void printMainMenu();

/** Main program **/
long* _VETOR_PRINCIPAL;
long _TAMANHO_VETOR_PRINCIPAL;
int main() {
	_VETOR_PRINCIPAL = criaVetorDecrescente(TAMANHO_INICIAL);
	_TAMANHO_VETOR_PRINCIPAL = TAMANHO_INICIAL;
	mainMenu();
	clearScreen();
	return EXIT_SUCCESS;
}

/** Implementations **/
void header() {
	char *aux = (char*)malloc(80*sizeof(char));
	filledLine();
	line(SYSTEM_NAME, 'C');
	sprintf(aux, "Tamanho vetor atual: %lu", _TAMANHO_VETOR_PRINCIPAL);
	line(aux, 'R');
	filledLine();
	printWarning();
}

void mainMenu() {

	char *opt = (char*)malloc(sizeof(char));

	while (1) {
		clearScreen();
		printMainMenu();
		printf("Choose your option: ");
		scanf(" %[^\n]", opt);

		switch(*opt) {
			case '1':
				// selection sort
				break;

			case '2':
				// bubble sort
				break;

			case '3':
				// Insertion sort
				break;

			case '4':
				// Merge sort
				break;

			case '5':
				// Quick sort
				break;

			case '6':
				// Counting sort
				break;

			case '7':
				// Bucket sort
				break;

			case '8':
				// Configurar vetor
				break;

			case 'a':
			  // Trigger auto test
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
	line("7. Bucket Sort", 'L');
	emptyLine();
	line("8. Configurar vetor", 'L');
	line("0. Sair", 'R');
	emptyLine();
	filledLine();
}