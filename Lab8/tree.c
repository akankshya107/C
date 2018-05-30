#include "tree.h"
void add(TNode tree, TNode tnode){
	TNode temp = tree;
	TNode node = createNode(tnode->value);
	char p;
	if(temp->left==NULL || temp->right==NULL){
		if(node->value<temp->value && temp->left==NULL){
			temp->left=node;
			if(temp->balance==0) temp->balance=-1;
			else temp->balance=0;
			return;
		}
		else if(node->value>=temp->value && temp->right==NULL){
			temp->right=node;
			if(temp->balance==0) temp->balance=1;
			else temp->balance=0;
			return;
		}
	}
	while(1){
		if(node->value<temp->value){
			if(temp->left!=NULL) {temp=temp->left;}
			else{
				if(temp->balance==0) temp->balance=-1;
				else temp->balance=0;
				temp->left=node;
				break;
			}
		}
		else{
			if(temp->right!=NULL) {temp=temp->right;}
			else{
				if(temp->balance==0) temp->balance=1;
				else temp->balance=0;
				temp->right=node;
				break;
			}
		}
	}
	return balanceAdd(tree, node);
}

TNode find(TNode tree, int val){
	TNode temp = tree;
	while(temp->value!=val){
		if(val<temp->value) temp=temp->left;
		else temp=temp->right;
	}
	return temp;
}

void delete(TNode tree, int val){
	TNode temp = tree;
	while(temp->value!=val){
		if(val<temp->value){
			temp=temp->left;
		}
		else{
			temp=temp->right;
		}
	}
	if(temp->left==NULL && temp->right==NULL){
		free(temp);
	}
	else if(temp->left!=NULL){
		temp->value=temp->left->value;
		delete(temp->left,temp->left->value);
	}
	else{
		temp->value=temp->right->value;
		delete(temp->right, temp->right->value);
	}
	return balanceDel(tree, temp);
}

TNode createNode(int val){
	TNode treenode = (TNode)malloc(sizeof(TNode*));
	treenode->value=val;
	treenode->right=NULL;
	treenode->left=NULL;
	treenode->balance=0;
	return treenode;
}

void balanceAdd(TNode tree, TNode temp){
	TNode *arr=(TNode*)malloc(sizeof(TNode)*10000);
	TNode test=tree;
	int i=0;
	arr[i]=tree;
	while(test!=temp){
		if(temp->value<test->value){
			arr[++i]=test->left;
			test=test->left;
		}
		else{
			arr[++i]=test->right;
			test=test->right;
		}
	}
	int hl, hr;
	for(int j=i-1; j>=0; j--){
		TNode left = arr[j]->left;
		TNode right = arr[j]->right;
		hl=height(left);
		hr=height(right);
		if(hr-hl>1 || hl-hr>1) {
			if(j>0){
				if(arr[j-1]->left==arr[j]) arr[j-1]->left=rotate(arr[j+2], arr[j+1], arr[j]);
				else arr[j-1]->right=rotate(arr[j+2], arr[j+1], arr[j]);
			}
			else tree=rotate(arr[j+2], arr[j+1], arr[j]);
		}
		if(hl>hr) arr[j]->balance=-1;
		else if(hl<hr) arr[j]->balance=1;
		else arr[j]->balance=0;
	}
}

int height(TNode x){
	if(x==NULL) return 0;
	if(x->left==NULL && x->right==NULL) return 1;
	if(x->left==NULL) return 1+height(x->right);
	if(x->right==NULL) return 1+height(x->left);
	return 1+max(height(x->left), height(x->right));
}

int max(int x, int y){
	if(x>=y) return x;
	return y;
}
TNode rotate(TNode x, TNode y, TNode z){
	TNode a,b,c,T0,T1,T2,T3;
	//compare to figure out the above 
	if(x->value<y->value){
		if(y->value<z->value){a=x, b=y; c=z;}
		else if(x->value>z->value){a=z; b=x; c=y;}
		else{a=x; b=z; c=y;}
	}
	else{
		if(x->value<z->value){a=y; b=x; c=z;}
		else if(y->value>z->value){a=z; b=y; c=x;}
		else{a=y; b=z; c=x;}
	}
	if(z->left==y){
		T3=z->right;
		if(y->left==x){
			T2=y->right;
			T0=x->left;
			T1=x->right;
		}
		else{
			T0=y->left;
			T1=x->left;
			T2=x->right;
		}
	}
	else{
		T0=z->left;
		if(y->left==x){
			T3=y->right;
			T1=x->left;
			T2=x->right;
		}
		else{
			T1=y->left;
			T2=x->left;
			T3=x->right;
		}
	}
	//swap pointers
	//cases to be considered: Z is root and Z is not a root
	b->left=a;
	b->right=c;
	a->left=T0;
	a->right=T1;
	c->left=T2;
	c->right=T3;
	return b;
}

void balanceDel(TNode tree, TNode temp){
	return;
}
