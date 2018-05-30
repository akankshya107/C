#include <stdio.h>
typedef struct{
	char* Name;
	float CGPA;
}Record;

typedef struct{
	int size;
	int no_of_rec;
	Record *arr[];
}Element;

void merge(Element *Ls1, int sz1, Element *Ls2, int sz2, Element *Ls); //merge two lists of sz1 and sz2, memory for merged list provided to the function
Element* readFromFile(FILE *f, int k); //reads k elements from file
Element* addEle(Element* l, char *name, float cg); //adds a new record into the array
Element* resizeList(Element *l, int size); //reallocates memory to array
Record* newRec(); //makes new blank Record 
Element* newList(int size); //makes new blank list
void mergeSort(Element *list, int st, int en); //mergesort(iterative/recursive) algorithm
void mergeFiles(FILE *f1, FILE *f2, FILE *out); //merge two files 
int divideSortedFiles(FILE *pr); //divide a large file into subsequent files and returns no. of files
Record* readRec(FILE *f); //read a record from a file
void mergesortfiles(FILE *f); //mergesort algorithm for large files
