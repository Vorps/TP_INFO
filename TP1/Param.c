#include "Param.h"
#include <stdio.h>
long hachage(char *key){
	Hash hash;
	for(int i = 0; i < sizeof(long); i++) hash.data[i] = '\0';
	for(int i = 0; key[i] != '\0' && i < sizeof(long); i++) hash.data[i] = key[i];
	return hash.hash;
}

/**
---Parseur---
char **argv 			: Le tableau de chaine de caractère  
size_t args_size 		: La taille du tableau argv 
ApplyParam applyParam 	: Fonction pour appliquer le paramétrage
void * setup 			: Structure pour stocker le paramétrage
**/
void setParam(char **argv, size_t args_size, ApplyParam applyParam, void * setup){
	for(int j = 1; j < args_size; j+= 1+*(argv[j]+1) != '-')
		if(*argv[j] == '-') applyParam(argv[j], j+1 < args_size ? argv[j+1] : 0, setup);	
}