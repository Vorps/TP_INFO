#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exe_3.h"

int main(int argc, char **argv){

	SetupSearch setupSearch = defaultSetupSearch;// Strucure par défaut
		// Modification des informations en fonction des arguments de main
	setParam(argv, argc, getSetupSearch, &setupSearch);
	showSearch(&setupSearch); // Affiche les informations
	// Initialisation de la structure Result
	Result result = {0,0, setupSearch.setupFunction.range.min, setupSearch.setupFunction.range.max};

	// Faire, tant que la |f(x)| > epsilon  
	do{
		//Modifie la structure result
		setupSearch.searchZero(setupSearch.setupFunction.function, &result);
		if(result.step > MAX_STEP){ // En cas de non convergence
			printf("Pas de résultats\n");
			exit(EXIT_FAILURE);
			break;
		}
	}
	while(fabs(setupSearch.setupFunction.function(result.result)) > EPSILON);
	printf("Résultat : %.10f en %d étapes.\n", result.result, result.step);
	return EXIT_SUCCESS;
}


void getSetupSearch(char *key, char *value, void *setupSearch){
	switch(hachage(key)){
		case HASH_BISECTION: // --bisection
			((SetupSearch *)setupSearch)->searchZero = bisection;
			((SetupSearch *)setupSearch)->nameFunction = "bisection";
			break;
		case HASH_SECANTE: // --secante
			((SetupSearch *)setupSearch)->searchZero = secante;
			((SetupSearch *)setupSearch)->nameFunction = "secante";
			break;
		case HASH_FAUSSE_POSITION: // --fausse_position
			((SetupSearch *)setupSearch)->searchZero = fausse_position;
			((SetupSearch *)setupSearch)->nameFunction = "fausse_position";
			break;
		case HASH_HELP: // --help
			printf("------HELP------\nSearch algorithme\n\t--bisection --secante --fausse_position --gradient\n");
		default:
			getSetupFunctions(key, value, &(((SetupSearch *)setupSearch)->setupFunction));
			break;
	}
	
}

void showSearch(SetupSearch *setupSearch){
	printf("------SETUP------\n");
	showFunctions(&(setupSearch->setupFunction));
	printf("Search algorithme\n\tAlgorithme de recherche du zéros de la fonction : %s\n", setupSearch->nameFunction);
}


void bisection(Function function, Result *result){
	double tmp = (result->b-result->a)/2+result->a;
	if(function(result->a)*function(tmp) < 0) result->b = tmp;
	else result->a = tmp;
	result->step++;
	result->result = tmp;
}

double secante_it(Function function, double x_n, double x_n1){
	if(function(x_n1)-function(x_n) == 0){
		printf("Division par zeros\n");
		exit(EXIT_FAILURE);
	}
	return x_n-function(x_n)*(x_n1-x_n)/(function(x_n1)-function(x_n));
}

void secante(Function function, Result *result){
	double tmp = result->b;
	result->b = secante_it(function, result->a, result->b);
	result->a = tmp;
	result->step++;
	result->result = tmp;
}

void fausse_position(Function function, Result *result){
	double tmp = result->b;
	result->b = secante_it(function, result->a, result->b);
	if(function(result->b)*function(result->a) < 0) result->a = tmp;
	result->step++;
	result->result = tmp;
}