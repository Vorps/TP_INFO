#include "Functions.h"
#include "Param.h"
#include<stdio.h>
#include<string.h>
double polynomial(double x){
	return pow(x, 3)-3*pow(x, 2)-3*x-35;
}

double exponential(double x){
	return (exp(10*x)-1)/(exp(10*x)+1)-0.5;
}

double sinusoide(double x){
	return cos(x+3*M_PI/8);
}

double square(double x){ 
	return pow(x,2); 
}

void getSetupFunctions(char *key, char *value, void *setupFunction){
	switch(hachage(key)){
		case HASH_SQUARE: // --square
			((SetupFunction *)setupFunction)->function = square;
			((SetupFunction *)setupFunction)->nameFunction = "square";
			break;
		case HASH_POLYNOMIAL: // --polynomial
			((SetupFunction *)setupFunction)->function = polynomial;
			((SetupFunction *)setupFunction)->nameFunction = "polynomial";
			break;
		case HASH_EXPONENTIAL: // --exponential
			((SetupFunction *)setupFunction)->function = exponential;
			((SetupFunction *)setupFunction)->nameFunction = "exponential";
			break;
		case HASH_SINUSOIDE: // --sinusoide
			((SetupFunction *)setupFunction)->function = sinusoide;
			((SetupFunction *)setupFunction)->nameFunction = "sinusoide";
			break;
		case HASH_HELP:
			printf("Functions \n\t--square --polynomial --exponential --sinusoide\n");
		default:
			getRange(key, value, &(((SetupFunction *)setupFunction)->range));
			break;
	}
}

void showFunctions(SetupFunction *setupFunction){
	showRange(&(setupFunction->range));
	printf("Functions \n\tFonction : %s\n", setupFunction->nameFunction);
}