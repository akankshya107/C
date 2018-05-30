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

void merge(Element *Ls1, int sz1, Element *Ls2, int sz2, Element *Ls);
Element* readFromFile(FILE *f);
Element* addEle(Element* l, char *name, float cg);
Element* resizeList(Element *l, int size);
Record* newRec();
Element* newList(int size);
void mergeSort(Element *list, int st, int en);
