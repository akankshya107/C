#include "tree.h"
TNode createTree(){
	srand(time(NULL));
	int key = rand()%(21) + 150;
	TNode t=createNode(key);
	TNode x;
	for(int i=0; i<10000; i++){
		key=rand()%(21) + 150;
		//printf("%d\n", key);
		x=createNode(key);
		add(t,x);
		free(x);
	}
	return t;
}

int inOrder(TNode tree, int k){
	int i=0;
	TNode *arr=(TNode*)malloc(sizeof(TNode)*10000);
	TNode temp=tree;
	while(temp!=NULL){
		arr[i++]=temp->left;
	}
	if(i<k) return 0;
	while(i>k) i--;
	
}
