#ifndef EXE_2_H
#define EXE_2_H

#include "Functions.h"

#include "FileValue.h"
static const double TE = 1;

#define HASH_TE 0x65742d

typedef struct SetupFunctionE SetupFunctionE;


struct SetupFunctionE{
	SetupFunction setupFunction;
	double te;
} static const defaultSetupFunctionE = {defaultSetupFunction, TE};



void getSetupFunctionE(char *, char *, void *);
void showFunctionE(SetupFunctionE *);
void showValues(Value *, size_t);

#endif