#define ELEM_TYPE_LL
#ifndef DEFINE_MY_OWN
struct LL{
	int val;
	struct LL *next;
};
typedef struct LL Element;
#endif
#include "iterate.h"
Iterator* createIterator(Element *head){
	Iterator *it=(Iterator*)malloc(sizeof(Iterator));
	it->e=head;
	return it;
}
bool hasMoreElements(Iterator *it){
	if(it->e->next==NULL) return false;
	return true;
}
Element* getNextElement(Iterator *it){
	if(!hasMoreElements(it)) return NULL;
	Element *temp=it->e->next;
	it->e=it->e->next;
	return temp;
}
