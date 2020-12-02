#include "exe_1.h"  //Define NMIN, NMAX
#include "Number.h" //Define getSafeNumber
#include <stdio.h>  //Define printf
#include <stdlib.h> //Define EXIT_SUCCESS, rand, srand
#include <time.h>   //Define time
//#include<assert.h> Pour les tests

int main(int argc, char **argv){
	/*//Génération d'une variable aléatoire discrète de loi uniforme sur le support [[NMIN, NMAX]]
	#ifdef TEST
		assert(NMAX-NMIN+1 % 2 && NMAX-NMIN+1 < RAND_MAX); //Vérification de la contrainte sur l'intervalle
	#endif
	srand(time(NULL));
	int randomNumber = (rand() & (NMAX-NMIN))+NMIN;
	int step = 0;//Comptabilise le nombre d'étapes nécessaires pour trouver le nombre
	int number;
	// Exécuté tant que le joueur n'a pas trouvé randomNumber
	while(1){
		getSafeNumber(&number, NMIN, NMAX); //Récupération du nombre
		step++;
   		if(randomNumber != number)
			printf("%s\n", number > randomNumber ? "-" : "+"); //Indication
		else break;
	}
	printf("Win !!! Steps n°%d\n", step);
	*/return EXIT_SUCCESS;
}