#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "image.h"

image_t *creer_image(){
	image_t *img;
	img = malloc(sizeof(image_t));
	img->w = 0;
	img->h = 0;
	img->path = NULL;
	img->buff = NULL;	
	return img;
}

image_t *copier_image(image_t *src){
	image_t *dst;
	int i;
	dst = malloc(sizeof(image_t));
	if(src == NULL){
		fprintf(stderr, "La source est vide\n");
	}
	dst->w = src->w;
	dst->h = src->h;
	dst->path = malloc(sizeof(char)*(strlen(src->path)+1));
	strcpy(dst->path, src->path);
	dst->buff = malloc(sizeof(unsigned char *)*(src->w*src->h));
	for(i = 0; i < src->w*src->h; i++){
		dst->buff[i] = src->buff[i];
	}
	return dst;
}

void detruire_image(image_t *p){
	if(p == NULL){
		fprintf(stderr, "Le pointeur est vide\n");
		return;
	}
	free(p->path);
	free(p->buff);
	free(p);
}
