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
        cout << "Usage: " << argv[0] << " <imageIn.pgm>" << endl;
        return 1;
    }

    clock_t t1, t2;

	// *********************
	// * RECUPERATION NOMS + MOYENNES *
	// *********************

	char** images = new char*[10000]; // tableau pour nom des images
    for(int i = 0; i < 10000; i++) {
        images[i] = new char[16];
    }
	int* moyennes = new int[10000]; // tableau pour moyenne des images

	OCTET* img; // image courante
 	allocation_tableau(img, OCTET, TAILLE);
    int moyenne; // moyenne de l'image courante

    DIR* rep = NULL; // répertoire d'image de reference
    if((rep = opendir("./data")) == NULL) {
        exit(1);
    }
    struct dirent* ent; // structure "fichier"
    int i = 0;
    t1 = clock();
    while((ent = readdir(rep)) != NULL) { // stockage des noms dans le tableau "images"
        if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 && strcmp(ent->d_name, "Licence.txt") != 0 && strcmp(ent->d_name, ".DS_Store") != 0) {
            string str = "data/" + (string)ent->d_name;
            copy(str.begin(), str.end(), images[i]);
            i++;
        }
    }
    t2 = clock();
    cout << (float)(t2-t1)/CLOCKS_PER_SEC << endl;

    cout << images[2] << endl;

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
    cout << (float)(t2-t1)/CLOCKS_PER_SEC << endl;

    for(int i = 0; i < 10000; i++) {
        cout << moyennes[i] << endl;
    }

	// ************
	// * TRI DATA *
	// ************

	//TODO appeler les deux tableaux en parametre et modifier les deux en meme temps selon moyenne[]
	// quickSort(images, 0, 10000);


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

    delete img;
	delete[] images;
	delete[] moyennes;

	return 0;
}
