#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h> // memcpy()

#include "sorting.h"

void bubbleSort(int* array, unsigned int size) {
	int swapped = 0;

	do {
		swapped = 0;

		for(unsigned int i = 0; i < size - 1; i++) {
			if(array[i] > array[i+1]) {
				int tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				swapped = 1;
			}
		}
	} while(swapped);
}

int* bubbleSortCopy(int* tab, unsigned int size) {
	int* copy = malloc(sizeof(int) * size);
	memcpy(copy, tab, size * sizeof(int));
	int swapped = 0;

	do {
		swapped = 0;

		for(unsigned int i = 0; i < size - 1; i++) {
			if(copy[i] > copy[i+1]) {
				int tmp = copy[i];
				copy[i] = copy[i+1];
				copy[i+1] = tmp;
				swapped = 1;
			}
		}
	} while(swapped);

	return copy;
}

void selectionSort(int* array, unsigned int size) {
	int minimum;

	for(unsigned int i = 0; i < size - 1; i++) {
		minimum = i;

		for(unsigned int j = i + 1; j < size; j++) {
			if(array[minimum] > array[j]) {
				minimum = j;
			}
		}

		int tmp = array[i];
		array[i] = array[minimum];
		array[minimum] = tmp;
	}
}

void insertionSort(int* array, unsigned int size) {
	int selected;

	for(unsigned int i = 1; i < size; i++) {
		selected = i;
		for(int j = i - 1; j >= 0; j--) {
			if(array[j] > array[selected]) {
				int tmp = array[j];
				array[j] = array[selected];
				array[selected] = tmp;
				selected--;
			} else {
				break;
			}
		}
	}
}