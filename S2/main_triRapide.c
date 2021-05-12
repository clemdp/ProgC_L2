#include <stdio.h>
#include <stdlib.h>
#include "utilitaires_tableaux.h"
#include "tri_rapide.h"

void main(){
	int tab1[10];
	init_tab_alea(tab1, 10);
	triRapide(tab1, 10);
	afficher_tab(tab1, 10);
}
