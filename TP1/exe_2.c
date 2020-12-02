#include <stdio.h> //Define printf
#include <stdlib.h> //Define EXIT_SUCCESS atof malloc free
#include "exe_2.h" // SetupFunctionE getSetupFunctionE showFunctionE showValues
#include "Param.h" //hachage setParam
#include "Number.h" //isNumber


int main(int argc, char **argv){
	SetupFunctionE setupFunctionE = defaultSetupFunctionE; // Strucure par défaut
	// Modification des informations en fonction des arguments de main
	setParam(argv, argc, getSetupFunctionE, &setupFunctionE); 
	showFunctionE(&setupFunctionE); // Affiche les informations

	// Nombre de couples (x,y)
	// Les valeurs des paramètres sont récupérées dans leur structure respective.
	int number = (setupFunctionE.setupFunction.range.max-setupFunctionE.setupFunction.range.min)/setupFunctionE.te+1;
	Value *values = (Value *) malloc(sizeof(Value)*number);

	int i = 0;
	for(double x = setupFunctionE.setupFunction.range.min; x <= setupFunctionE.setupFunction.range.max; x+=setupFunctionE.te){
		Value value = {x, setupFunctionE.setupFunction.function(x)}; // Initialisation d un nouveau couple
		values[i++] = value; //Ajout du couple au tableau
	}
	// Ecriture du tableau en texte
	writeValue("resultsFile/values.dat", values, number);
	// Ecriture du tableau en binaire
	writeBinaryValue("resultsFile/values.bin", values, number);

	
	Value *readValues = (Value *) malloc(sizeof(Value)*number);
	//Lecture du tableau en mode texte
	readValue("resultsFile/values.dat", readValues, number);
	//Affiche le résulat de la lecture
	showValues(readValues, number);
	Value *readBinaryValues = (Value *) malloc(sizeof(Value)*number);
	//Lecture du tableau en mode binaire
	readBinaryValue("resultsFile/values.bin", readBinaryValues, number);
	//Affiche le résulat de la lecture
	showValues(readBinaryValues, number);
	//Evite les fuites de mémoire
	free(values);
	free(readValues);
	free(readBinaryValues);
	return EXIT_SUCCESS;
}

//Affichage des couples (x, f(x))
void showValues(Value *values, size_t values_size){
	printf("----Valeurs----\n");
	for(int i = 0; i < values_size; i++){
		printf("%.2lf\t%.2lf\n", values[i].x, values[i].y);
	}
}

void getSetupFunctionE(char *key, char *value, void *setupFunctionE){
    switch(hachage(key)){
        case HASH_TE: // -te
            //La valeur vérifie les critères d'un temps d'échantillonnage.
            if(isNumber(value) && atof(value) > 0) ((SetupFunctionE *)setupFunctionE)->te = atof(value);
            break;
        case HASH_HELP:
            printf("------HELP------\nSampling \n\t-te\n");
            // Pas de break l'help est parsé dans les fonctions supérieures.
        default:
            getSetupFunctions(key, value, &(((SetupFunctionE *)setupFunctionE)->setupFunction));
            break;
    }
    if(hachage(key) == HASH_HELP) exit(EXIT_SUCCESS); //Si la key == '--help' on arrête l'exécution
}


void showFunctionE(SetupFunctionE *setupFunctionE){
	printf("------SETUP------\n");
	showFunctions(&(setupFunctionE->setupFunction));
	printf("Sampling\n\tTe : %lf\n", setupFunctionE->te);
}