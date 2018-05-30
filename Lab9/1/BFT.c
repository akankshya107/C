#include "que.h"
void treeTraverse(Tree *t){
	printf("BFTTT");
	if(!isEmptyTree(t)){
		Queue *currentSet= newQ();
		currentSet=addQ(currentSet, returnEle(t));
		Tree *tempt;
		Element *tempe;
		Iterator *i;
		while(!isEmptyQ(currentSet)){
			tempt=front(currentSet); delQ(currentSet);
			printf("%d\n", getRootVal(tempt));
			if(getChildren(tempt)!=NULL) i=getChildren(tempt);
			else continue;
			while(hasMoreElements(i)){ 
				tempe=getNextElement(i);
				if(!tempe->t==NULL){
					currentSet=addQ(currentSet, returnEle(tempe->t)); 
				}
			}
		}
	}
}
