#include "cycle.h"
#include <string.h>
LinkedList* makeCircularList(LinkedList *ls){
	char* x=testCyclic(ls);
	if(strcmp(x,"cyclic")==0){
		Node *ptr=ls->head;
		while(ptr!=ls->tail->next){
			Node *p=ptr;
			ptr=ptr->next;
			myfree(p);
			printf("%u\n",spaceAllocated);
		}
		return ls;
	}
	if (strcmp(x,"linear")==0){
		ls->tail->next=ls->head;
		return ls;
	}
	return NULL;
}
