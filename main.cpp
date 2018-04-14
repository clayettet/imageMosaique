#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <dirent.h>
#include <time.h>

#include "image_ppm.h"

int COTE = 512;
int TAILLE = COTE*COTE;

using namespace std;

void selection_sort(int* array, char** array2, unsigned int size) {
    int tmp;
    char* tmp2 = new char[16];

    for(unsigned int i = 0; i < size-1; i++) {
        int min = i;

        for(unsigned int j = i+1; j < size; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }

        tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;

        tmp2 = array2[i];
        array2[i] = array2[min];
        array2[min] = tmp2;
    }
}

// //utilisé dans quicksort()
// void echanger(int tableau[], int a, int b){
//     int temp = tableau[a];
//     tableau[a] = tableau[b];
//     tableau[b] = temp;
// }
//
//
// //tri rapide (meilleur que bubble)
// void quickSort(int tableau[], int debut, int fin){
//     int gauche = debut-1;
//     int droite = fin+1;
//     const int pivot = tableau[debut];
//
//     /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
//     if(debut >= fin)
//         return;
//
//     /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
//        autre de gauche à droite, à la recherche d'éléments mal placés,
//        que l'on permute. Si les deux parcours se croisent, on arrête. */
//     while(1){
//         do droite--; while(tableau[droite] > pivot);
//         do gauche++; while(tableau[gauche] < pivot);
//
//         if(gauche < droite)
//             echanger(tableau, gauche, droite);
//         else break;
//     }
//
//     /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
//        supérieurs au pivot. On a donc deux groupes de cases à trier. On réappelle QuickSort*/
//     quickSort(tableau, debut, droite);
//     quickSort(tableau, droite+1, fin);
// }


int main(int argc, char const *argv[]) {
    if(argc != 4) {
        cout << "Usage: " << argv[0] << " <imageIn.pgm> <imageOut.pgm> <nbBlocLargeur>" << endl;
        return 1;
    }

    // *************
	// * Variables *
	// *************

    clock_t t1, t2;

    int nbBlocLargeur = atoi(argv[3]);
    int largeurBloc = COTE / nbBlocLargeur;
    int tailleBloc = largeurBloc * largeurBloc;
    int nbBloc = nbBlocLargeur * nbBlocLargeur;
    int premierIndiceBloc;
    int indiceBloc;

    char** images = new char*[10000]; // tableau pour nom des images
    for(int i = 0; i < 10000; i++) {
        images[i] = new char[16];
    }
	int* moyennes = new int[10000]; // tableau pour moyenne des images

	OCTET* img; // image courante
	OCTET* tmp; // image courante
 	allocation_tableau(img, OCTET, TAILLE);
 	allocation_tableau(tmp, OCTET, TAILLE);
    int moyenne; // moyenne de l'image courante

    DIR* rep = NULL; // répertoire d'image de reference

    struct dirent* ent; // structure "fichier"
    int l = 0; // indice recuperation noms d'image

	// ********************************
	// * RECUPERATION NOMS + MOYENNES *
	// ********************************

    if((rep = opendir("./data")) == NULL) {
        exit(1);
    }

    t1 = clock();
    while((ent = readdir(rep)) != NULL) { // stockage des noms dans le tableau "images"
        if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 && strcmp(ent->d_name, "Licence.txt") != 0 && strcmp(ent->d_name, ".DS_Store") != 0) {
            string str = "data/" + (string)ent->d_name;
            copy(str.begin(), str.end(), images[l]);
            l++;
        }
    }
    t2 = clock();
    cout << "time to read : " << (float)(t2-t1)/CLOCKS_PER_SEC << endl;

    if(closedir(rep) == -1) { // fermeture de l'objet repertoire
        exit(-1);
    };

    t1 = clock();
    for(int k = 0; k < 10000; k++) {
        lire_image_pgm(images[k], img, TAILLE);

        moyenne = 0;
        for(int i = 0; i < COTE; i++) {
            for(int j = 0; j < COTE; j++) {
                moyenne += img[i*COTE+j];
            }
        }
        moyennes[k] = moyenne / TAILLE;
    }
    t2 = clock();
    cout << "time to average : " << (float)(t2-t1)/CLOCKS_PER_SEC << endl;

	// ************
	// * TRI DATA *
	// ************

	t1 = clock();
    selection_sort(moyennes, images, 10000); // tri les deux tableaus selon les moyennes
    t2 = clock();
    cout << "time to sort : " << (float)(t2-t1)/CLOCKS_PER_SEC << endl;

	// **********************
	// * RECUPERATION IMAGE *
	// **********************

	lire_image_pgm((char*)argv[1], img, TAILLE);

	// *******************************
	// * DECOUPAGE EN BLOC + MOYENNE *
	// *******************************

	for(int k = 0; k < nbBloc; k++) {
        premierIndiceBloc = 0;
        moyenne = 0;

        for(int i = 0; i < largeurBloc; i++) {
            for(int j = 0; j < largeurBloc; j++) {
                indiceBloc = 0;
                moyenne += img[indiceBloc];
            }
        }

        moyenne /= tailleBloc;

        for(int i = 0; i < tailleBloc; i++) {
            for(int j = 0; j < tailleBloc; j++) {
                indiceBloc = 0;
                tmp[i] = moyenne;
            }
        }
    }

	// *******************************
	// * RECHERCHE PLUS PROCHE IMAGE *
	// *******************************

	//TODO

    delete img;
    delete tmp;
	delete[] images;
	delete[] moyennes;

	return 0;
}
