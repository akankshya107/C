#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef int Ele;

typedef struct{
	int size;
	int no_of_rec;
	Ele arr[];
}Stack;

Ele top(Stack *s);
Ele pop(Stack *s);
Stack* push(Stack *s, Ele e);
int size(Stack *s);
bool isEmpty(Stack *s);
Stack* newStack();
