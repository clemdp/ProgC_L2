#include <stdio.h>
#include <stdlib.h>

//Exo 1

void main(){
	int tab[8] = {3, 5, 12, 2, 6, 15, 32, 34};
	int min, max;
	float somme;
	min_max_moy_rec(tab, 8, &somme, &min, &max);
	printf("Le min est : %d, le max est : %d, et la somme est : %f \n", min, max, somme);
}	
