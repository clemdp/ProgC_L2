#include <stdlib.h>
#include "noyau.h"
#include <stdio.h>
#include <string.h>

#define TMP_STR_SIZE 128

noyau_t *creer_noyau(unsigned int dim){
	noyau_t *matrice;						//matrice contenant le filtre
	matrice = malloc(sizeof(int *)*dim);	//allocation de la matrice
	matrice.dim = dim;
	return matrice;
}

void detruire_noyau(noyau_t *pn){
	int i;
	for(i = 0; i < pn.dim; i++){
		free(pn[i].coeff);
	}
	free(pn);
}

noyau_t *charger_noyau(char *nom_fichier){
	FILE *f;
	noyau_t *matrice;
	int dim, i;
	f = fopen(nom_fichier, "r");
	fscanf(f, "%d", dim);
	fgetc
	return ;
}
