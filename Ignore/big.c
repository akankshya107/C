#include "big.h"
Node* newNode(int val){
	Node *n=(Node*)malloc(Node);
	n->val=0;
	n->next=NULL;
	return n;
}
BigNumber* newNumber(FILE *ptr){
	int x;
	BigNumber *big = (BigNumber*)malloc(sizeof(BigNumber));
	fscanf(ptr,"%d",x);
	Node *n = newNode(x);
	big->head=n;
	Node pbig = big->head;
	while(fscanf(ptr,"%d",x)==1){
		n = newNode(x);
		pbig->next=n;
		pbig=pbig->next;
	}
	return big;
}
BigNumber* addBig(BigNumber *a, BigNumber *b){
	Node *pa = a->head;
	Node *pb = b->head;
	while(){
	
	}
}
