#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "image_ppm.h"

#define cote 512
#define taille cote*cote

using namespace std;


//utilisé dans quicksort()
void echanger(int tableau[], int a, int b){
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}


//tri rapide (meilleur que bubble)
void quickSort(int tableau[], int debut, int fin){
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1){
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On réappelle QuickSort*/
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
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

	//TODO appeler les deux tableaux en parametre et modifier les deux en meme temps selon moyenne[]
	quickSort(images, 0, 10000);


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
