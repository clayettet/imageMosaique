#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "image_ppm.h"

#define cote 512
#define taille cote*cote

using namespace std;

void bubbleSort(int* array, string* name, unsigned int size) {
	int swapped = 0;

	do {
		swapped = 0;

		for(unsigned int i = 0; i < size - 1; i++) {
			if(array[i] > array[i+1]) {
				swap(array[i], array[i+1]);
				swap(name[i], name[i+1]);
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
	// * RECUPERATION NOMS + MOYENNES *
	// *********************

	//TODO
	//creation tableau pour nom des images
	int* images = new int[10000];
	//creation tableau pour moyenne des images
	int* moyennes = new int[10000];
	//tableau de lecture image
	OCTET* img;
 	allocation_tableau(img, OCTET, taille);

	int moyenne; // moyenne de l'image en cours
	string imageName;

	for(int i = 0; i<10000 ; i++){
		images[i]=i; //tableau de nom
		moyenne = 0;
		imageName = "data/"+i+".pgm";
  		lire_image_pgm(imageName.c_str(), img, taille);
		for(int j = 0; j<cote ; j++){
			for(int h = 0; h<cote; h++){
				moyenne += img[i*cote+h]; //ajout du pixel courant dans calcul moyenne
			}
		}
		//moyennes[i] = moyenne/taille; //calcul moyenne finale dans tab
	}


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

	delete[] images;
	delete[] moyennes;
	return 0;
}
