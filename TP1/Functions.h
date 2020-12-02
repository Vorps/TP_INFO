#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>
#include "Range.h"
#define HASH_SINUSOIDE 0x6f73756e69732d2d
#define HASH_EXPONENTIAL 0x656e6f7078652d2d
#define HASH_POLYNOMIAL 0x6f6e796c6f702d2d
#define HASH_SQUARE 0x6572617571732d2d

double polynomial(double); //5
double exponential(double); //0.10
double sinusoide(double); //0.39
double square(double); //0

typedef struct SetupFunction SetupFunction;
typedef double (*Function)(double x);

void getSetupFunctions(char *, char *, void *);


struct SetupFunction{
	Range range;
	Function function;
	char *nameFunction;
} static const defaultSetupFunction = {defaultRange, square, "square"};

void showFunctions(SetupFunction *);

#endif