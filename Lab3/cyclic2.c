#include "cycle.h"
//Linked list reversal algorithm
char* testCyclic(LinkedList *ls){
	if (ls==NULL) return "what the fuck";
	if (ls->size==0) return "empty list";
	if (ls->size==1) return "singleton list";
	if (ls->size==2) return "only two lol";
	Node *prev=NULL;
	Node *curr=ls->head;
	Node *pnext;
	int x=ls->size;
	while(1){
		pnext=curr->next;
		curr->next=prev;
		prev=curr;
		curr=pnext;
		x--;
		if(x<0) return "cyclic";
		if(curr==NULL||pnext==NULL) return "linear";
	}
}

