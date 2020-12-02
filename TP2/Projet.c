#include <stdio.h>
#include <stdlib.h>
#include "Projet.h"
#include "Param.h"

int main(int argc, char **argv){
	Setup setup = defaultSetup;
	setParam(argv, argc, getSetup, &setup);
	showSetup(&setup);

	FILE* fileRead; // Fichier de lecture
	FILE* fileWrite; // Fichier de sortie
	
	unsigned char header[LONGUEUR_ENTETE];

	char nameReadFile[100]; 
	sprintf(nameReadFile, "%s.bmp", setup.nameImage); //Formatage du path

	fileRead=fopen(nameReadFile, "rb");
	if(fileRead == NULL){
		printf("Error open image !!!\n");
		exit(EXIT_FAILURE);
	}
	 // Lecture des 54 octets de l'entête
	fread(header, sizeof(char), LONGUEUR_ENTETE, fileRead);

	// Taille de l'image
	int width = getValue(header, 18);
	int height = getValue(header, 22);
	long int nb_pixels = width*height;

	//Allocation des canaux
	unsigned char *R = malloc(sizeof(unsigned char)*nb_pixels);
	unsigned char *G = malloc(sizeof(unsigned char)*nb_pixels);
	unsigned char *B = malloc(sizeof(unsigned char)*nb_pixels);

	//Récupération des valeurs des pixels
	read_RGB(fileRead, nb_pixels, R, G, B);
	
	//Application du filtre
	setup.filter(nb_pixels, R, G, B);

	char nameWriteFile[100];
	//Formatage du path de l'image modifié 
	sprintf(nameWriteFile, "%s_%s.bmp", setup.nameImage, setup.nameFilter);

	fileWrite=fopen(nameWriteFile, "wb");
	//Recopie de l'entête bmp
	fwrite(header, sizeof(unsigned char), LONGUEUR_ENTETE, fileWrite);
	//Écriture des valeurs de pixels dans le fichier
	write_RGB(fileWrite, nb_pixels, R, G, B);

	//Libère les ressources
	fclose(fileRead);
	fclose(fileWrite);
	return EXIT_SUCCESS;
}

void getSetup(char *key, char *value, void *setup){
	switch(hachage(key)){
		case 0x49656d616e2d: // -nameI
			((Setup *)setup)->nameImage = value;
			break;
		case 0x5247422d2d: // --BGR
			((Setup *)setup)->filter = RGB_to_BGR;
			((Setup *)setup)->nameFilter = "RGB_to_BGR";
			break;
		case 0x42472d2d: // --GB
			((Setup *)setup)->filter = RGB_to_GB;
			((Setup *)setup)->nameFilter = "RGB_to_GB";
			break;
		case 0x747265766e692d2d: // --invert
			((Setup *)setup)->filter = invertColor;
			((Setup *)setup)->nameFilter = "invert";
			break;
		case 0x706c65682d2d: // --help
			printf("------HELP------\nSetup\n\t-nameI --BGR --GB --invert\n");
			exit(EXIT_SUCCESS);
		default:
			break;
	}
}


void showSetup(Setup *setup){
	printf("------SETUP------\n");
	printf("\tPath : %s Filtre : %s\n", setup->nameImage, setup->nameFilter);
}


void RGB_to_BGR(size_t nb_pixels, unsigned char *R, unsigned char *G, unsigned char *B){
	unsigned char *tmp = malloc(sizeof(unsigned char)*nb_pixels);
	for(int i = 0; i < nb_pixels; i++) *(tmp+i) = *(B+i);
	for(int i = 0; i < nb_pixels; i++) *(B+i) = *(R+i);
	for(int i = 0; i < nb_pixels; i++) *(R+i) = *(tmp+i);
}

void RGB_to_GB(size_t nb_pixels, unsigned char *R, unsigned char *G, unsigned char *B){
	for(int i = 0; i < nb_pixels; i++) *(R+i) = 0;
}

void invertColor(size_t nb_pixels, unsigned char *R, unsigned char *G, unsigned char *B){
	for(int i = 0; i < nb_pixels; i++) *(R+i) = 255-*(R+i);
	for(int i = 0; i < nb_pixels; i++) *(G+i) = 255-*(G+i);
	for(int i = 0; i < nb_pixels; i++) *(B+i) = 255-*(B+i);
}

int getValue(unsigned char* header, int offset){
	Value value;
	for(int i = 0; i < 4; i++) value.data[i] =  header[offset+i];
	return value.value;
}

void read_RGB(FILE *file, size_t nb_pixels, unsigned char *R, unsigned char *G, unsigned char *B){
	for(int i = 0; i < nb_pixels; i++){
		fread(B+i, sizeof(unsigned char), 1, file);
		fread(G+i, sizeof(unsigned char), 1, file);
		fread(R+i, sizeof(unsigned char), 1, file);
	}
}

void write_RGB(FILE *file, size_t nb_pixels, unsigned char *R, unsigned char *G, unsigned char *B){
	for(int i = 0; i < nb_pixels; i++){
		fwrite(B+i, sizeof(unsigned char), 1, file);
		fwrite(G+i, sizeof(unsigned char), 1, file);
		fwrite(R+i, sizeof(unsigned char), 1, file);
	}
}