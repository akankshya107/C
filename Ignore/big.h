#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
	int val;
	struct node *next;
}
typedef struct node Node;
typedef struct{
	Node *head;
}BigNumber;

Node* newNode(int val);
BigNumber* newNumber(FILE *ptr);
BigNumber* addBig(BigNumber *a, BigNumber *b);
BigNumber* subBig(BigNumber *a, BigNumber *b);
BigNumber* mulBig(BigNumber *a, BigNumber *b);
BigNumber* divBig(BigNumber *a, BigNumber *b);
BigNumber* moduloBig(BigNumber *a, BigNumber *b);
