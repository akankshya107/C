#include "exstack.h"
#include <stdlib.h>
Stack* newStack(int size){
	Stack *stack=(Stack*)malloc(sizeof(Stack)+ sizeof(int)*size);
	stack->top=-1;
	for(int i=0; i<size; i++){
		stack->s[i]=0;
	}
	return stack;
}

int pop(Stack *stack){
	return stack->s[(stack->top)--];
}

void push(Stack *stack, int x){
	stack->s[++(stack->top)]=x;
}
