#include "SeqList.h"
#include <stdio.h>
int main(void){
  Key d1, d2, d3;
  SeqList *sl=newList();
  Element *e1= createElem(9);
  Element *e2= createElem(7);
  Element *e3= createElem(4);
  Element *e4= createElem(8);
  Element *e5= createElem(6);
  Element *e6= createElem(5);
  sl = insertAtFront(sl,e1);
  sl = insertAtFront(sl,e2);
  sl = insertAtFront(sl,e3);
  sl = insertAtFront(sl,e4);
  sl = insertAtFront(sl,e5);
  sl = insertAtFront(sl,e6);
  SeqList *sort = insertionsort(sl);
	printf("%d", sort->size);
  Element *ptr = sort->head;
  while(ptr!=NULL){
    printf("Key=%d\n", ptr->key);
    ptr=ptr->next;
  }  
  return 0;
}
