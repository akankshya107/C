#include "stack.h"
Ele top(Stack *s){
	if(!isEmpty(s)){
		s->no_of_rec--;
		return s->arr[s->no_of_rec-1];
	}
}

Ele pop(Stack *s){
	if(!isEmpty(s)){
		Ele e = s->arr[s->no_of_rec-1];
		s->arr[s->no_of_rec-1]=0;
		s->no_of_rec--;
		return e;
	}
}

Stack* push(Stack *s, Ele e){
	if(s->no_of_rec==s->size){
		s->arr=realloc(s->arr, 2*(s->size));
		s->size=2*s->size;
		for(int i=s->no_of_rec; i<s->size; i++){
			s->arr[i]=0;
		}
	}
	s->arr[s->no_of_rec++]=e;
	return s;
}

int size(Stack *s){
	return s->no_of_rec;
}

bool isEmpty(Stack *s){
	if (s->no_of_rec==0) return true;
	return false;
}

Stack* newStack(){
	Stack *s = (Stack*)malloc(sizeof(Stack) + sizeof(Ele)*20);
	for(int i=0; i<20; i++){
		s->arr[i]=0;
	}
	s->size=20;
	s->no_of_rec=0;
	return s;
}
