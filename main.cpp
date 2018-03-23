#include <iostream>
#include <string>

#include "image_ppm.h"

using namespace std;

void bubbleSort(int* array, string* name, unsigned int size) {
	int swapped = 0;

	do {
		swapped = 0;

		for(unsigned int i = 0; i < size - 1; i++) {
			if(array[i] > array[i+1]) {
				swap(array[i], array[i+1]);
				swap(string[i], string[i+1]);
				swapped = 1;
			}
		}
	} while(swapped);
}

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        cout << "Usage: " << argv[0] << "<imageIn.pgm>" << endl;
        return 1;
    }

	// *********************
	// * RECUPERATION DATA *
	// *********************

	//TODO

	// ***********
	// * MOYENNE *
	// ***********

	//TODO

	// ************
	// * TRI DATA *
	// ************

	//TODO

	// **********************
	// * RECUPERATION IMAGE *
	// **********************

	//TODO

	// *******************************
	// * DECOUPAGE EN BLOC + MOYENNE *
	// *******************************

	//TODO

	// *******************************
	// * RECHERCHE PLUS PROCHE IMAGE *
	// *******************************

	//TODO

	return 0;
}
