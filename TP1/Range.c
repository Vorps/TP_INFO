#include <stdio.h>
#include <stdlib.h>

#include "Range.h"
#include "Number.h"
#include "Param.h"



void getRange(char *key, char *value, void *range){
	switch(hachage(key)){
		case HASH_MIN: // -min
			if(isNumber(value) && atof(value) < ((Range *)range)->max) ((Range *)range)->min = atof(value);
			break;
		case HASH_MAX: // -max
			if(isNumber(value) && atof(value) > ((Range *)range)->min) ((Range *)range)->max = atof(value);
			break;
		case HASH_HELP:
			printf("Range\n\t -min -max\n");
			break;
		default:
			break;
	}
}

void showRange(Range *range){
	printf("Range\n\tMin : %.2f Max : %.2f\n", range->min, range->max);
}

