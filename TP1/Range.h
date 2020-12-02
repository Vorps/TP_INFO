#ifndef RANGE_H
#define RANGE_H
	#include <stdio.h>

	#define HASH_HELP 0x706c65682d2d 
	#define HASH_MIN 0x6e696d2d
	#define HASH_MAX 0x78616d2d

	static const double MIN = -10;
	static const double MAX = 10;

	typedef struct Range Range;

	void getRange(char *, char *, void *);

	struct Range{
		double min;
		double max;
	} static const defaultRange = {MIN, MAX};

	void showRange(Range *);

#endif


