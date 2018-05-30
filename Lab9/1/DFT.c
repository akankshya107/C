#include "stack.h"
void treeTraverse(Tree *t){
	if(isEmptyTree(t)) return;
	Element *tempe;
	Tree *temp;
	Iterator *i;
	Stack *currentSet=newStack();
	currentSet=push(currentSet, returnEle(t));
	do{
		temp=top(currentSet); pop(currentSet);
		printf("%d\n", getRootVal(temp));
		if(getChildren(temp)!=NULL) i=getChildren(temp);
		else continue;
		while(hasMoreElements(i)){
			tempe=getNextElement(i);
			if(!(tempe->t)==NULL){
				currentSet=push(currentSet, returnEle(tempe->t)); 
			}
		}
	}while(!isEmpty(currentSet));
}

