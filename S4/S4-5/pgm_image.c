#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "image.h"
#define TMP_STR_SIZE 256

image_t *charger_image_pgm(char *nom_fichier){
	FILE *f;						//var ouverture fichier
	image_t *img;					//var copie image
	char c, *s;						//var lecture contenu f
	int i, n, j;					//var lecture contenu f
	unsigned int *nb_niveaux_gris;	//var contenant les nvx de gris
	char ligne_lue[TMP_STR_SIZE];	//char contenant la ligne courante
	enum format {BIN, ASCII} pgm_form;
	//création du pointeur image
	img = creer_image();
	//récupération du nom de fichier donné en arg
	img->path = nom_fichier;
	//ouverture du fichier en lecture seule
	f = fopen(img->path, "r");
	//vérification ouverture
	if(f == NULL){
		fprintf(stderr, "Fichier inexistant\n");
		detruire_image(img);
		return NULL;
	}
	//lecture de la premiere ligne & verif format
	n = fscanf(f, "%c%d\n", &c, &i);
	if (n != 2 || i != 2){
		fprintf(stderr, "Erreur lecture format\n");
		fclose(f);
		return NULL;
	}
	//determination du format
	if(i == 2){
		pgm_form = BIN;
	} else if (i == 5){
		pgm_form = ASCII;
	}
	//passage des lignes de commentaire
	s = fgets(ligne_lue, 256, f);	
	while(s != NULL && ligne_lue[0] == '#'){
		fgets(ligne_lue, 256, f);
	}
	//recupération de la taille de l'image
	sscanf(ligne_lue, "%ld %ld\n", &img->w, &img->h);
	//allocation memoire buffer
	img->buff = malloc(sizeof(unsigned char)*(img->w*img->h));
	if(!img){ 
		fprintf(stderr, "Erreur allocation buffer");
		fclose(f);
		detruire_image(img);
		return NULL;
	}
	//recupération des niveaux de gris
	sscanf("%ld", nb_niveaux_gris);
	//lecture de la suite du fichier
	if(pgm_form == ASCII){
		for(j = 0; j < img->h * img->w; j++){
			fscanf(f, "%c\n", &img->buff[j]);
		}
	}
	if(pgm_form == BIN){
		fread(img->buff, sizeof(unsigned char), img->h*img->w, f);
	}
	return img;
}

int sauver_image_pgm(char *nom_fichier, image_t *img){
	int i;					//var iterative
	FILE *f;				//pointeur sur fichier
	
	//verification de l'existance de img
	if(!img){
		fprintf(stderr, "Image inexistante\n");
		return 0;
	}
	//ouverture en écriture de fichier
	f = fopen(nom_fichier, "w+");
	//verification de la creation du fichier
	if(f == NULL){
		fprintf(stderr, "Pas de creation fichier\n");
		return 0;
	}
	//copie du contenu de img dans f
	fprintf(f, "P2\n");							//ecriture format
	fprintf(f, "%ld %ld\n", img->h, img->w);		//ecriture taille h x w
	fprintf(f, "255\n");						//ecriture nvx gris
	for(i = 0; i < (img->w*img->h); i++){
		fprintf(f, "%hhu\n", img->buff[i]);		//copie contenu buffer
	}
	return 1;
}
