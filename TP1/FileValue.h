#ifndef FILE_VALUE_H
#define FILE_VALUE_H
#include <stddef.h>
typedef struct Value Value;

struct Value{
	double x;
	double y;
};

void writeValue(char *, Value *, size_t);
void writeBinaryValue(char *, Value *, size_t);

void readValue(char *, Value *, size_t);
void readBinaryValue(char *, Value *, size_t);

#endif