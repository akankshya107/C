#include "tree.h"
//int height=0;
Tree* createTree(int no_of_children){
	createTree5(no_of_children, 0);
	/*Tree *t = (Tree*)malloc(sizeof(Tree));
	t->value=rand();
	if(height==MAX_HEIGHT) return t;
	height++;
	int no;
	Tree *tempt;
	Element *head=(Element*)malloc(sizeof(Element));
	head->t=NULL;
	Element *tempe=head;
	t->children=head; 
	t->it=createIterator(head);
	for(int i=0; i<no_of_children; i++){
		no=rand()%10;
		tempt=createTree(no);
		height--;
		tempe->next=(Element*)malloc(sizeof(Element));
		tempe->next->t=tempt;
		tempe=tempe->next;
	}
	height++;
	return t;*/
}
Tree* createTree5(int no_of_children, int height){
	Tree *t = (Tree*)malloc(sizeof(Tree));
	t->value=rand();
	if(height==MAX_HEIGHT) return t;
	int no;
	Tree *tempt;
	Element *head=(Element*)malloc(sizeof(Element));
	head->t=NULL;
	Element *tempe=head;
	t->children=head; 
	t->it=createIterator(head);
	for(int i=0; i<no_of_children; i++){
		no=rand()%10;
		tempt=createTree5(no, height+1);
		tempe->next=(Element*)malloc(sizeof(Element));
		tempe->next->t=tempt;
		tempe=tempe->next;
	}
	return t;
}
bool isEmptyTree(Tree *t){
	if(!hasMoreElements(t->it)) return true;
	return false; 
}

int getRootVal(Tree *t){
	return t->value;
}

Iterator* getChildren(Tree *t){
	return t->it;
}
