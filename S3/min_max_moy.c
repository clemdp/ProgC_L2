#include <stdio.h>
#include <stdlib.h>

//Exo 1

void min_max_moy(int tab[], int taille, float *moy, int *min, int *max){
	int i;
	*min = tab[0];
	*max = tab[0];
	*moy = tab[0];
	if (!tab){
		printf ("le tableau est vide\n");
		return;
	}
	for (i = 1; i < taille; i++){
		if (tab[i-1] < tab[i]){
			*max = tab[i];
			//printf ("val max %d \n", *max);
		}if (tab[i-1] > tab[i]){
			*min = tab[i];
			//printf ("val min %d \n", *min);
		} *moy = *moy + tab[i];
		//printf ("val moy %f \n", *moy);
	} *moy = *moy/taille;
}

void min_max_moy_rec(int tab[], int taille, float *somme, int *min, int *max){
	*min = tab[0];
	*max = tab[0];
	*somme = tab[0];
	if (!tab){
		printf("le tableau est vide\n");
		return;
	} if (taille == 1){
		return;
	} min_max_moy_rec(tab, taille-1, somme, min, max);
		
	if(*min > tab[taille-1]){
		*min = tab[taille-1];
		printf ("val min %d \n", *min);
	} if(*max < tab[taille-1]){
		*max = tab[taille-1];
		printf ("val max %d \n", *max);
	} *somme = *somme + tab[taille-1];
	printf ("somme : %f, taille : %d \n", *somme, taille);
}
