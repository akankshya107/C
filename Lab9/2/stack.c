#include "stack.h"
struct dirent* top(Stack *s){
	Ele *ptr=s->tail;
	return ptr->el;
}

struct dirent* pop(Stack *s){
	if(isEmpty(s)) return NULL;
	if(s->size==1) {Ele *ptr= s->head; s->head=NULL; s->tail=NULL; s->size--; return ptr->el;}
	Ele *ptr = s->head;
	while(ptr->next!=s->tail){ ptr=ptr->next; }
	Ele *ret = s->tail;
	s->tail=ptr;
	s->size--;
	return ret->el;
}

Stack* push(Stack *s, Ele *e){
	if(s->size==0){
		s->head=e;
		s->tail=e;
	}else{
		s->tail->next=e;
		s->tail=e;
	}
	s->size++;
	return s;
}

int size(Stack *s){
	return s->size;
}

bool isEmpty(Stack *s){
	if (s->size==0) return true;
	return false;
}

Stack* newStack(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->size=0;
	s->head=NULL;
	s->tail=NULL;
	return s;
}

Ele* returnEle(struct dirent *ele){
  Ele *e = (Ele*)malloc(sizeof(Ele));
  e->el=ele;
  e->next=NULL;
  return e;
}
