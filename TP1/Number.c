#include "Number.h"
#include <stdio.h>
#include <ctype.h>

int isNumber(char *numberChar){
	for(; (*numberChar) != '\0'; numberChar++){
		if(!isdigit(*numberChar) && *numberChar != '-' && *numberChar != '.') return 0;
	}
	return 1;
}

void getSafeNumber(int *number, const int NMIN, const int NMAX){
	printf("Number [[%d, %d]]?\n", NMIN, NMAX);
	do{
		while(!scanf("%d", number)){
			char c;
			while((c = getchar()) != ' ' && c != '\n'); //Supprime les caractères problématiques
		}
	} while(*number < NMIN || *number > NMAX); //Boucle scanf si le nombre récupéré n'est pas dans l'intervale
}