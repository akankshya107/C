#define ELEM_TYPE_ARRAY
#include "iterate.h"
int main(void){
	/*Element *e1=(Element*)malloc(sizeof(Element));
	e1->val=1;
	Element *e2=(Element*)malloc(sizeof(Element));
	e2->val=2;
	e1->next=e2;
	Element *e3=(Element*)malloc(sizeof(Element));
	e3->val=3;
	e2->next=e3; 
	e3->next=NULL;
	Iterator *i=createIterator(e1);
	while(hasMoreElements(i)){
		printf("%d\n", getNextElement(i)->val);
	}
	*/
	Array *a = (Array*)malloc(sizeof(Array)+sizeof(Element)*5);
	a->size=5;
	for(int i=0; i<5; i++){
		a->no[i]=i*i;
	}
	Iterator *it = createIterator(a);
	while(hasMoreElements(it)){
		printf("%d\n", getNextElement(it));
	}
	return 0;
}
