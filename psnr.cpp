#include <iostream>

#include "image_ppm.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if(argc != 3) {
        cout << "Usage: " << argv[0] << " <originImg> <refImg>" << endl;
        exit(EXIT_FAILURE);
    }

    int height, width;

    OCTET* imgIn;
    OCTET* imgRef;

    lire_nb_lignes_colonnes_image_ppm((char*)argv[1], &height, &width);
    int size = height * width;

    allocation_tableau(imgIn, OCTET, size);
    lire_image_pgm((char*)argv[1], imgIn, size);
    allocation_tableau(imgRef, OCTET, size);
    lire_image_pgm((char*)argv[2], imgRef, size);


    double psnr = 0.0;
    double MSE = 0.0;

    for(int k = 0; k < size; k++) {
        MSE += pow((double)imgIn[k] - (double)imgRef[k], 2.0);
    }

    MSE /= size;

    psnr = 10.0 * log10(pow(255.0, 2.0) / MSE);

    cout << psnr << endl;

    delete imgRef;
    delete imgIn;

    return 0;
}
