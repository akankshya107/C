#include "tree.h"
int main(void){
	srand(time(NULL));
	Tree *t = createTree(rand()%10);
	printf("%d\n", getRootVal(t));
	/*Iterator *i=getChildren(t);
	i=getChildren(getNextElement(i)->t);
	while(hasMoreElements(i)){
		printf("%d\n", getNextElement(i)->t->value);
	}*/
	treeTraverse(t);
	return 0;
}
