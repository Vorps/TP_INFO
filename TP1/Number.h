#ifndef NUMBER_H
#define NUMBER_H
int isNumber(char *);
// Fonction pour récupérer de manière sécurisé un entier dans le dommaine {NMIN, ..., NMAX}
// La contrainte est d'utiliser scanf ...
void getSafeNumber(int *, int, int);
#endif
