#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
struct Ele{
  Tree *el;
  struct Ele *next;
};
typedef struct Ele Ele;
typedef struct{
	int size;
	Ele *head;
	Ele *tail;
}Stack;

Tree* top(Stack *s);
Tree* pop(Stack *s);
Stack* push(Stack *s, Ele *e);
int size(Stack *s);
bool isEmpty(Stack *s);
Stack* newStack();
Ele* returnEle(Tree *ele);
