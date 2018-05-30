#include <stdlib.h>
#include <time.h>
#include "cycle.h"

LinkedList* createList(unsigned int N){
	LinkedList *ls = (LinkedList*)myalloc(sizeof(LinkedList));
	ls->size=N;
	ls->head=NULL;
	ls->tail=NULL;
	for (unsigned int i=0; i<N; i++){
		unsigned int x = rand()%N;
		Node *node = returnNode(x);
		ls=addNode(ls,node);
	}
	return ls;
}

Node* returnNode(unsigned int x){
	Node *node = (Node*)myalloc(sizeof(Node));
	node->data=x;
	node->next=NULL;
}

LinkedList* addNode(LinkedList *ls, Node *node){
	if (ls->head==NULL){
		ls->head=node;
		ls->tail=node;
		node->next=NULL;
	}
	else{
		ls->tail->next=node;
		ls->tail=node;
	}
	return ls;
}

LinkedList* createCycle(LinkedList *ls){
	srand(time(NULL));
	int x = rand()%2;
	printf("x=%d\n", x);
	if (x==1){
		unsigned int r=(rand()%(ls->size));
		Node *ptr=ls->head;
		while(r>0){
			ptr=ptr->next;
			r--;
		}
		Node *adr=ptr;
		ls->tail->next=adr;
	}
	return ls;
}

