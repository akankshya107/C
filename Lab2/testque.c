#include <stdio.h>
#include "que.h"
int main(void){
  int d1, d2, d3;
  Queue *q = newQ();
  printf("Enter element data");
  scanf("%d%d%d", &d1, &d2, &d3);
  Element *e1 = returnEle(d1);
  Element *e2 = returnEle(d2);
  Element *e3 = returnEle(d3);
  q=addQ(q,e1);
  q=addQ(q,e2);
  q=addQ(q,e3);
  Element *p=q->head;
  printf("%p\n", p);
  printf("%p\n", q->tail);
  while(p!=NULL){
    printf("%d\n", p->data);
    p=p->next;
  }
  printf("Element at the front is: %d\n", front(q)->data);
  q=delQ(q);
  printf("Element at the front is: %d\n", front(q)->data);
  q=delQ(q);
  printf("Element at the front is: %d\n", front(q)->data);
  return 0;
}
