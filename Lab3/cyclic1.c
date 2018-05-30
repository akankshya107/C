#include "cycle.h"
//Hare and Tortoise algorithm
char* testCyclic(LinkedList *ls){
	if (ls->size==0) return "empty list";
	if (ls->size==1) return "singleton list";
	if (ls->size==2) return "only two lol";
	Node *hare=ls->head;
	Node *tort=hare;
	do{
		if(hare==NULL||hare->next==NULL) return "linear";
		hare=hare->next->next;
		tort=tort->next;
	}while(hare!=tort);
	return "cyclic";
}
