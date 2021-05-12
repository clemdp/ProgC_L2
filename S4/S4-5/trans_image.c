#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "noyau.h"

//Mise en négatif de la source
image_t *negatif(image_t *src){
	image_t *imodif;				//Declaration de la dest
	int i, j;						//Var iteratives
	imodif = creer_image();			//Allocation de imodif
	//Verification de la creation de imodif
	if(!imodif){
		fprintf(stderr, "Erreur creation destination\n");
		return NULL;
	}
	//Verification de l'existance de src
	if(!src){
		fprintf(stderr, "Erreur de source\n");
		return NULL;
	}
	imodif = copier_image(src);		//Copie de src dans imodif

	//Inversion de la valeur des pixels de imodif
	for(i = 0; i < imodif->h; i++){
		for(j = 0; j < imodif->w; j++){
			if(VAL(imodif, i, j) <= 255/2){
				 VAL(imodif, i, j) += 255;
			}
			if(VAL(imodif, i, j) > 255/5){
				VAL(imodif, i, j) = VAL(imodif, i, j) - 255;
			}
		}
	} 
	return imodif;
}

//Rotation de l'image source
image_t *rotation(image_t *src, int angle){
	image_t *irot;					//Declaration de la dest
	int i, j;						//Var iteratives
	irot = creer_image();			//Allocation de irot
	//Verification de la creation de irot
	if(!irot){
		fprintf(stderr, "Erreur creation destination\n");
		return NULL;
	}	
	//Verification de l'existance de src
	if(!src){
		fprintf(stderr, "Erreur de source\n");
		return NULL;
	}
	//Verification de la validite de l'angle
	if(angle != 90 || angle != 180 || angle != 270){
		fprintf(stderr, "Angle non valide\n");
		detruire_image(irot);
		return NULL;
	}
	//Rotation de 90°
	if(angle == 90){
		irot->h = src->w;
		irot->w = src->h;
		for(i = 0; i < irot->h; i++){
			for(j = 0; j < irot->w; j++){
				//on échange les pixels de coord (i, j)
				//avec les pixels de coord (j, i)
				irot->buff[VAL(irot, i, j)] = src->buff[VAL(src, i, j)];
			}
		}
	}
	//rotation de 180°
	if(angle == 180){
		irot->h = src->h;
		irot->w = src->w;
		for(i = 0; i < irot->h; i++){
			for(j = 0; j < irot->w; j++){
				//si les pixels sont après le milieu de l'image
				//on retire les valeurs des bords
				if(i > (irot->h)/2 && j > (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, i-(src->h), j-(src->w))];
				}
				//si les pixels sont avant le milieu de l'image
				//on ajoute la valeur des bords
				if(i <= (irot->h)/2 && j <= (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, (src->h)-i, (src->w)-j)];
				}
				//si un des deux pixels est avant et l'autre après
				//le milieu de l'image, on ajoute et retire
				//respectivement la valeur des bords
				if(i > (irot->h)/2 && j <= (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, i-(src->h), (src->w)-j)];
				}
				//si un des deux pixels est avant et l'autre après
				//le milieu de l'image, on ajoute et retire
				//respectivement la valeur des bords
				if(i <= (irot->h)/2 && j > (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, i-(src->h), (src->w)-j)];
				}
			}
		}
	}
	//rotation de 270°
	if(angle == 270){
		irot->h = src->w;
		irot->w = src->h;
		for(i = 0; i < irot->h; i++){
			for(j = 0; j < irot->w; j++){
				//si les pixels sont après le milieu de l'image
				//on echange i et j et on retire les valeurs des bords
				if(i > (irot->h)/2 && j > (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, j-(src->w), i-(src->h))];
				}
				//si les pixels sont avant le milieu de l'image
				//on échange i et j et on ajoute la valeur des bords
				if(i <= (irot->h)/2 && j <= (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, (src->w)-j, (src->h)-i)];
				}
				//si un des deux pixels est avant et l'autre après
				//le milieu de l'image, on échange i et j puis 
				//on ajoute et retire respectivement la valeur des bords
				if(i > (irot->h)/2 && j <= (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, (src->w)-j, i-(src->h))];
				}
				//si un des deux pixels est avant et l'autre après
				//le milieu de l'image, on échange i et j puis 
				//on ajoute et retire respectivement la valeur des bords
				if(i <= (irot->h)/2 && j > (irot->h)/2){
					irot->buff[VAL(irot, i, j)] = src->buff
					[VAL(src, (src->w)-j, i-(src->h))];
				}
			}
		}
	}
	return irot;
}

image_t *modifier_lumin(image_t *src, int pourcent){
	image_t *modif;				//création de l'image modifiée
	int i, j; 					//variables itératives
	modif = creer_image();		//on alloue modif
	//verification de l'allocation de modif
	if(!modif){
		fprintf(stderr, "Erreur creation modif\n");
		return NULL;
	}
	//verification de l'existance de source
	if(!src){
		fprintf(stderr, "La source n'existe pas\n");
		return NULL;
	}
	for(i = 0; i < src->h; i++){
		for(j = 0; j < src->w; j++){
			modif->buff[VAL(modif, i, j)] = src->buff
			[VAL(src, i, j)]*((pourcent-100)/100);
		}
	}
	return NULL;
}

image_t *bruiter_image(image_t *src, int pourcent)
	{
	return NULL;
	}

image_t *filtrer_median(image_t *src)
	{
	return NULL;
	}

image_t *convoluer(image_t *src, noyau_t *pn)
	{
	return NULL;
	}
