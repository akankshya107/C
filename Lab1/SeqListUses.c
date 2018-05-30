#include "SeqList.h"
#include <stdio.h>
SeqList* merge(SeqList *s1, SeqList *s2){
  SeqList *sl = newList();
  Element *p1 = s1->head;
  Element *p2 = s2->head;
  while(1){
    if (p1!=NULL) {
      Element *pd1 = createElem(p1->key);
      p1=p1->next;
      sl=insertInOrder(sl,pd1);
    }
    if (p2!=NULL) {
      Element *pd2 = createElem(p2->key);
      p2=p2->next;
      sl=insertInOrder(sl,pd2);
    }
    if (p1==NULL && p2==NULL) break;
  }
  return sl;
}

SeqList* insertionsort(SeqList *sl){
	SeqList *s = newList();
	Element *ptr = sl->head;
	while(ptr!=NULL){
		Element *e = createElem(ptr->key);
		s=insertInOrder(s,e);
		ptr=ptr->next;
	}
	return s;
}
