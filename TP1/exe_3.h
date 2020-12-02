#ifndef EXE_3_H
#define EXE_3_H

#include "Range.h"
#include "Param.h"
#include "Functions.h"

#define EPSILON 0.000001
#define MAX_STEP 10000

#define HASH_BISECTION 0x7463657369622d2d
#define HASH_SECANTE 0x746e616365732d2d
#define HASH_FAUSSE_POSITION 0x6573737561662d2d

typedef struct Result Result;
typedef struct SetupSearch SetupSearch;
typedef void (*FunctionSearch)(Function, Result *);
struct Result{
	int step;
	double result;
	double a,b;
};

void bisection(Function function, Result *result);
void secante(Function function, Result *result);
void fausse_position(Function function, Result *result);


void getSetupSearch(char *, char *, void *);

struct SetupSearch{
	SetupFunction setupFunction;
	FunctionSearch searchZero;
	char * nameFunction;
} static const defaultSetupSearch = {defaultSetupFunction, bisection, "bisection"};

void showSearch(SetupSearch *);


#endif