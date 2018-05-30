#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
typedef struct{
	int currsize;
	int no_of_rec;
	char *arr[];
}Array;
int hash(char *str);
int collisionCount(Array *a, int baseNumber, int tableSize);
Array* parse(FILE *ptr);
int filter(char *str);
Array* resize(Array *a, int size);
void profile(Array *a);
int selectPrime(int lo, int hi);
