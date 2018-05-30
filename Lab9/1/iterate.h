#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#ifdef ELEM_TYPE_LL
typedef struct{
	Element *e;
}Iterator;

Iterator* createIterator(Element *head);
bool hasMoreElements(Iterator *it);
Element* getNextElement(Iterator *it);
#endif
#ifdef ELEM_TYPE_ARRAY
typedef struct {
	Array *arr;
	int count;
}Iterator;

Iterator* createIterator(Array *a);
bool hasMoreElements(Iterator *it);
Element* getNextElement(Iterator *it);
#endif
