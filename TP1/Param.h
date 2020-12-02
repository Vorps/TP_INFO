#ifndef PARAM_H
#define PARAM_H

#include <stddef.h>
#include <stdarg.h>

union Hash{
	char data[sizeof(long)];
	long hash;
};

typedef union Hash Hash;

typedef void (*ApplyParam)(char *, char *, void *);


long hachage(char *);

void setParam(char **, size_t, ApplyParam, void *);


#endif