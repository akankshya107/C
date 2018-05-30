#include "tree.h"
int main(void){
	TNode t=createTree();
	add(t,createNode(30));
	add(t,createNode(700));
	add(t,createNode(2000));
	TNode temp = t;
	//printf("%d\n", t->value);
	find(t,163);
	delete(t,30);
	return 0;
}
