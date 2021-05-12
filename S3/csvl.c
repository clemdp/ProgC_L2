#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compte_mots_chaine(char *chaine) {
	int nbmots = 0, i = 0;
	for(chaine[i]; chaine[i]!="\0"; i++){
		if(chaine[i] == " "){
			nbmots++;
		}
	}return nbmots;
}

char **decompose_chaine(char *chaine){
	char **tabMots, *c;
	int i = 0, nbMots;
	nbMots = compte_mots_chaine(chaine);
	tabMots = malloc(sizeof(char**)*nbMots);
	for(chaine[i]; chaine[i] != "\0"; i++){
		if(chaine[i] != " "){
			c[i] += chaine[i];
		}
		tabMots[i] = c;
	}return tabMots;
}

char *compose_chaine(char **ptab_mots){
	int i = 0, j = 0;
	char *chaine;
	for(ptab_mots[i]; ptab_mots[i] != NULL; i++){
		for(*ptab_mots[j]; *ptab_mots[j]!="\0"; j++){
			chaine[j] += *ptab_mots[j];
		} chaine[j] += " ";
	}return chaine;
}
		
char **detruit_tab_mots(char **ptab_mots){
	//a completer
}

int compte_mots(char **ptab_mots){
	int nbMots, i = 0;
	for(ptab_mots[i]; ptab_mots[i] != NULL; i++){
		nbMots ++;
	}return nbMots;
}

void affiche_tab_mots(char **ptab_mots){
	
}

char **reduit_tab_mots(char **ptab_mots)
{
  /* a completer */
}
