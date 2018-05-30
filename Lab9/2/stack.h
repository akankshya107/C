#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
//#include "tree.h"
struct Ele{
  struct dirent *el;
  struct Ele *next;
};
typedef struct Ele Ele;
typedef struct{
	int size;
	Ele *head;
	Ele *tail;
}Stack;

struct dirent* top(Stack *s);
struct dirent* pop(Stack *s);
Stack* push(Stack *s, Ele *e);
int size(Stack *s);
bool isEmpty(Stack *s);
Stack* newStack();
Ele* returnEle(struct dirent *ele);
void treeTraverse(char *name);
