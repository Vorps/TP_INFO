#ifndef PROJET_H
#define PROJET_H

#define LONGUEUR_ENTETE 54 // la taille de l entete bmp

typedef union Value Value;
typedef struct Setup Setup;
typedef void (*Filter)(size_t, unsigned char *, unsigned char *, unsigned char *);

union Value{
	unsigned char data[4];
	int value;
};

void RGB_to_BGR(size_t, unsigned char *, unsigned char *, unsigned char *);

void RGB_to_GB(size_t, unsigned char *, unsigned char *, unsigned char *);

void invertColor(size_t, unsigned char *, unsigned char *, unsigned char *);


struct Setup{
	char *nameImage;
	Filter filter;
	char *nameFilter;
} defaultSetup = {"Docs/Mola", invertColor, "invert"};

int getValue(unsigned char *, int);

void read_RGB(FILE *, size_t, unsigned char *, unsigned char *, unsigned char *);

void write_RGB(FILE *, size_t, unsigned char *, unsigned char *, unsigned char *);


void getSetup(char *, char *, void *);
void showSetup(Setup *);

#endif