#include <stdio.h>
typedef struct{
	char *cd;
	char *bc;
	char *ed;
	char *fn;
	char *ln;
}Record;

typedef struct{
	int size;
	int no_of_rec;
	Record *arr[];
}Array;

Array* newArray(); //makes new Array
Record* newRecord(); //makes new Record
Array* insertIntoArray(Array *a, Record *rec); //inserts Record rec into Array arr, resizing array if it is full
Array* resizeArray(Array *a, int size); //resizes arr, and returns resized Array
Array* readFromFile(FILE *f); //reads from file and stores records in Array
Array* insertInOrder(Array *a, Record *r, int size); 
Array* insertionSort(Array *a, int size);
FILE* inputDistri(FILE *f, char *x);
FILE* duplicates(FILE *f);
FILE* single(FILE *f);
FILE* sorted(FILE *f);
FILE* reverse(FILE *f);
