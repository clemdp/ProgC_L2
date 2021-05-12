#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 8

/* ce sujet ne dispose pas d'une correction automatique */

void afficher_lab(int lab[DIM][DIM], char palette[]){
	int i, j;
	for (j = 0; j < DIM; j++){
		for (i = 0; i < DIM; i++){
			if (lab[i][j] == 0){
				printf("%c", palette[0]);
			}else {
				printf("%c", palette[1]);
			}//printf("Je suis dans afficher, boucle i");
		}//printf("Je suis dans afficher, boucle j");
		printf("\n");
	}
}

int chercher_chemin_rec(int lab[DIM][DIM], int lc, int cc){
	lab[lc][cc] = 2;	
	if (lc == DIM-1 && cc == DIM-1){
		//printf("Je suis dans chercher, cas 1");
		return 1;
	}if (lc<DIM-1 && lab[lc+1][cc]==0 && chercher_chemin_rec(lab, lc+1, cc)==1){
		//printf("Je suis dans chercher, cas 2");
		return 1; 
	}else if (cc<DIM-1 && lab[lc][cc+1]==0 && chercher_chemin_rec(lab, lc, cc+1)==1){
		//printf("Je suis dans chercher, cas 3");
		return 1;
	}else if (lc<DIM-1 && lab[lc-1][cc]==0 && chercher_chemin_rec(lab, lc-1, cc)==1){
		//printf("Je suis dans chercher, cas 4");
		return 1;
	}else if (cc<DIM-1 && lab[lc][cc-1]==0 && chercher_chemin_rec(lab,lc,cc-1)==1){
		//printf("Je suis dans chercher, cas 5");
		return 1;
	}else if (lc<DIM-2 && lab[lc+1][cc+1]==1 && lab[lc+2][cc]==1 && lab[lc+1][cc-1]==1){
		//printf("Je suis dans chercher, cas 6");
		return 3;
	}return 0;
}

int chercher_chemin(int lab[DIM][DIM]){
	int i, j;
	for (i = 0; i < DIM; i++){
		for (j = 0; j < DIM; j++){
			if (lab[i][j] == 0){
				lab[i][j] = 2;
			}else {
				j = j-1;
				i++;
				
			}
		}
	}return 1;			
}

int main (){
	char palette[2] = {' ', '*'};
	int i, j;
	int lab[DIM][DIM] = {{0,0,1,0,0,0,1,1},
	{1,0,0,1,1,0,1,0},
	{1,0,1,1,1,0,0,0},
	{1,0,0,1,0,0,1,1},
	{0,1,0,0,0,1,0,1},
	{0,0,0,1,0,1,0,1},
	{1,1,1,1,0,0,0,0},
	{1,0,1,1,0,0,0,0}};
	chercher_chemin_rec(lab, 0, 0);
	afficher_lab(lab, palette);
}
