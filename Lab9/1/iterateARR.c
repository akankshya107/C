#define ELEM_TYPE_ARRAY 
#ifndef DEFINE_MY_OWN
typedef int Element;
typedef struct array{
	int size;
	Element no[];
}Array;
#endif
#include "iterate.h"
Iterator* createIterator(Array *a){
	Iterator *i = (Iterator*)malloc(sizeof(Iterator));
	i->arr=a;
	i->count=-1;
	return i;
}
bool hasMoreElements(Iterator *it){
	if(it->arr->size-1==it->count) return false;
	return true;
}
Element getNextElement(Iterator *it){
	Element temp= it->arr->no[++it->count];
	it->count++;
	return temp;
}
