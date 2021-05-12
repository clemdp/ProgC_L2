#include "utilitaires_tableaux.h"
#include <stdio.h>

void triBulle(int tab[], int n){
	int i, j;
	for (i = n; i > 0; i = i-1){
		for (j = 0; j < i; j++){
			if (tab[j] > tab[j+1]){
				echanger_elem_tab(tab, j+1, j);
			}
		}
	}
}

void triBulleAmeliore(int tab[], int n){
	int i, j, permute = 1;
	if(tab_trie(tab, n)) return;
	for (i = n-1; i > 0 && permute == 1; i = i-1){
		permute = 0;
		for (j = 0; j < i; j++){
			if (tab[j] > tab[j+1]){
				echanger_elem_tab(tab, j+1, j);
				permute = 1;
			}
		}
	}
}

