#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Exo1

void main(){
	int i, min, max;
	float moy;
	int *tab = malloc(sizeof(int)*100);
	for(i = 1; i<=100; i++){
		tab[i-1] = i;
		min_max_moy(tab, i, &moy, &min, &max);
	}
	printf("Min = %d, Max = %d, Moy = %f\n", min, max, moy);
	if(min != 1){
		printf("Le min attendu 1, min obtenu : %d\n", min);
	} if (max != i-1){
		printf("Le max attendu %d, max obtenu : %d\n", i-1, max);
	} if (moy != 50.5){
		printf("Moy attendu 50.5, moy obtenu : %f\n", moy);
	}
	free(tab);
}
