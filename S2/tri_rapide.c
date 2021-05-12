#include "utilitaires_tableaux.h"
#include <stdlib.h>
#include <stdio.h>



void triRapide(int tab[], int n) {
	int temp, p = 0;
	if(!tab) return;

	while(i<n){
	
		if(tab[p] > tab[i]){
		


		}else{
			

			printf("i2 = %d, n2 = %d ", i, n);
			afficher_tab(tsup, n-1);
		}
	}//copier_tab(tinf, tab, n);
	//copier_tab(tsup, tab, n);
}


int partitionner(int tab[], int s, int n){
	int p = 0;
	int temp;
	if(!tab) return 0;
	if(tab[p] <= tab[s]){
		p++;
		echanger_elem_tab(tab, p, s);
	return p;
}

void triRapideAmeliore(int tab[], int s, int n){

}
