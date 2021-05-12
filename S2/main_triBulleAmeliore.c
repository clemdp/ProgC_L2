#include <stdio.h>
#include "utilitaires_tableaux.h"
#include "tri_bulle.h"

int main(){
	int tab1[10];
	init_tab_alea(tab1, 10);
	triBulleAmeliore(tab1, 10);
	afficher_tab(tab1, 10);
	return 0;
}
