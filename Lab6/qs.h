#include "exstack.h"
#include <stdio.h>
typedef struct{
	char *Name;
	long unsigned int empID;
}Record;

typedef struct{
	int size;
	int no_of_rec;
	Record *arr[];
}List;

void insertionSort(List *l, int lo, int hi);
void quickSort(List *l, int s); //iterative version of quicksort
int partition(List *l, int lo, int hi);
Record* newRec(); //new blank record
List* newList(int size); //new blank list
Record* readRec(FILE *f); //reads record from file
List* addRec(List *l, Record *r); //adds record to list, calls resize if list size is too small
List* resizeList(List *l, int size); // resizes list to double its size
List* readFromFile(FILE *f);
