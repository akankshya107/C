#include <stdbool.h>
#include <stdio.h>
#include "ex2.h"

struct Node{
	unsigned int data;
	struct Node *next;
};
typedef struct Node Node;

struct LinkedList{
	unsigned int size;
	struct Node *head;
	struct Node *tail;
};
typedef struct LinkedList LinkedList;

LinkedList* createList(unsigned int N); //generates N random numbers and stores them as a linear linked list
LinkedList* createCycle(LinkedList *ls); //tosses a coin– programmatically – to decide whether Ls must be linear or cyclic
char* testCyclic(LinkedList *ls); //returns true if list is cyclic, else false
Node* returnNode(unsigned int x);
LinkedList* addNode(LinkedList *ls, Node *node);
LinkedList* makeCircularList(LinkedList *ls); //returns circular list
