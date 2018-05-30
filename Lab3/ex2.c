#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>

//static Allocated *spaceAllocated;

void init(){
	spaceAllocated=(Allocated*)malloc(sizeof(Allocated));
	spaceAllocated->head=NULL;
	spaceAllocated->tsize=sizeof(Allocated);
	printf("%u\n", spaceAllocated->tsize);
}

void* myalloc(unsigned int size){
	static Space *x;
	x = (Space*)malloc(sizeof(Space));
	x->size=size;
	x->ptr=malloc(sizeof(size));
	Space *p=spaceAllocated->head;
	if (p==NULL){
		x->next=NULL;
		spaceAllocated->head=x;
	}
	else{
		while(p!=NULL){
			p=p->next;
		}
		x->next=NULL;
		p=x;
	}
	spaceAllocated->tsize+=size+sizeof(Space);
	return x->ptr;
}

void myfree(void *ptr){
	Space *p=spaceAllocated->head;
	while(p->next->ptr!=ptr){
		p=p->next;
	}
	spaceAllocated->tsize-=p->next->size + sizeof(Space);
	p->next=p->next->next;
	free(p);
}


